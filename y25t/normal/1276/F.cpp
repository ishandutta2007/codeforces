#include<bits/stdc++.h>
#define ll long long
#define N 400005
#define W 20

int n;
char s[N];

ll ans;

struct SAM{
	struct node{
		int fa,ch[26],len;
		node(){
			fa=len=0;
			for(int i=0;i<26;i++)
				ch[i]=0;
		}
	}t[N];
	int _t=1,lst=1,pos[N];
	inline void ins(int c,int id){
		int u=lst,v=pos[id]=lst=++_t;
		t[v].len=t[u].len+1;
		for(;u&&!t[u].ch[c];u=t[u].fa)
			t[u].ch[c]=v;
		if(!u){
			t[v].fa=1;
			return;
		}
		int w=t[u].ch[c];
		if(t[w].len==t[u].len+1){
			t[v].fa=w;
			return;
		}
		int x=++_t;
		t[x].fa=t[w].fa;
		for(int i=0;i<26;i++)
			t[x].ch[i]=t[w].ch[i];
		t[x].len=t[u].len+1;
		for(;u&&t[u].ch[c]==w;u=t[u].fa)
			t[u].ch[c]=x;
		t[w].fa=t[v].fa=x;
	}
	inline ll cal(){
		ll res=0;
		for(int i=1;i<=_t;i++)
			res+=t[i].len-t[t[i].fa].len;
		return res;
	}
}a,b;

namespace T1{
	std::vector<int> E[N];
	int p[N<<1],_p,dfn[N],dep[N];
	inline void dfs(int u){
		p[++_p]=u;
		dfn[u]=_p;
		for(auto v:E[u]){
			dep[v]=dep[u]+1;
			dfs(v);
			p[++_p]=u;
		}
	}
	int ln[N<<1],st[W][N<<1];
	inline int chkmn(int x,int y){
		return dep[x]<dep[y]?x:y;
	}
	inline void init(){
		for(int i=2;i<=b._t;i++)
			E[b.t[i].fa].push_back(i);
		dfs(1);
		ln[0]=-1;
		for(int i=1;i<=_p;i++)
			ln[i]=ln[i>>1]+1;
		for(int i=1;i<=_p;i++)
			st[0][i]=p[i];
		for(int j=1;j<W;j++)
			for(int i=1;i+(1<<j)-1<=_p;i++)
				st[j][i]=chkmn(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	}
	inline int lca(int x,int y){
		int l=dfn[x],r=dfn[y];
		if(l>r)
			std::swap(l,r);
		int k=ln[r-l+1];
		return chkmn(st[k][l],st[k][r-(1<<k)+1]);
	}
	inline int dis(int u,int v){
		return b.t[u].len+b.t[v].len-2*b.t[lca(u,v)].len;
	}
}

namespace T2{
	std::vector<int> E[N];
	ll f[N];
	std::set<std::pair<int,int>> S[N];
	inline void ins(int u,int v){
		if(S[u].count({T1::dfn[v],v}))
			return;
		auto it=S[u].insert({T1::dfn[v],v}).first;
		auto l=it==S[u].begin()?prev(S[u].end()):prev(it),r=next(it)==S[u].end()?S[u].begin():next(it);
		f[u]+=T1::dis(v,l->second)+T1::dis(v,r->second)-T1::dis(l->second,r->second);
	}
	inline void mrg(int u,int v){
		bool flg=0;
		if(S[u].size()<S[v].size()){
			std::swap(u,v);
			flg=1;
		}
		for(auto x:S[v])
			ins(u,x.second);
		S[v].clear();
		if(flg){
			std::swap(S[u],S[v]);
			std::swap(f[u],f[v]);
		}
	}
	inline void dfs(int u){
		for(auto v:E[u]){
			dfs(v);
			mrg(u,v);
		}
		ans+=f[u]/2*(a.t[u].len-a.t[a.t[u].fa].len);
	}
	inline void init(){
		for(int i=2;i<=a._t;i++)
			E[a.t[i].fa].push_back(i);
		for(int i=1;i<=a._t;i++)
			ins(i,1);
		for(int i=3;i<=n;i++)
			ins(a.pos[i-2],b.pos[i]);
		dfs(1);
	}
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<n;i++)
		a.ins(s[i]-'a',i);
	for(int i=n;i>1;i--)
		b.ins(s[i]-'a',i);
	ans+=2+a.cal()+b.cal();
	T1::init(),T2::init();
	a.ins(s[n]-'a',n);
	ans+=a.cal();
	printf("%lld\n",ans);
}