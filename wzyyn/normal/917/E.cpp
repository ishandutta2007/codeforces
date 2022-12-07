#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
struct node{
	int x,v,id;
};
vector<node> vQ[N];
vector<int> S[N];
int n,m,Q,ans[N];
int type[N],L[2][N];
char s[N];
struct Hash{
	int v1,v2,p1,p2;
	Hash(){
		v1=v2=0;
		p1=p2=1;
	}
	Hash(int _c){
		if (_c==-1){
			v1=v2=0;
			p1=p2=1;
		}
		else{
			v1=v2=_c+99;
			p1=233; p2=237;
		}
	}
	Hash operator +(const Hash &a)const{
		Hash ans;
		ans.p1=1ll*p1*a.p1%1000000007;
		ans.p2=1ll*p2*a.p2%1000000009;
		ans.v1=(v1+1ll*p1*a.v1)%1000000007;
		ans.v2=(v2+1ll*p2*a.v2)%1000000009;
		return ans;
	}
	bool operator <(const Hash &a)const{
		return v1==a.v1?v2<a.v2:v1<a.v1;
	}
	bool operator ==(const Hash &a)const{
		return v1==a.v1&&v2==a.v2;
	}
};
namespace SEG{
	const int M=10000005;
	int ls[M],rs[M],t[M],nd;
	void init(){
		for (;nd;--nd);
			ls[nd]=rs[nd]=t[nd]=0;
	}
	void change(int &nk,int k,int l,int r,int x,int y,int val){
		nk=++nd; t[nk]=t[k];
		ls[nk]=ls[k]; rs[nk]=rs[k];
		if (x<=l&&r<=y){
			t[nk]=max(t[nk],val);
			return;
		}
		int mid=(l+r)/2;
		if (x<=mid) change(ls[nk],ls[k],l,mid,x,y,val);
		if (y>mid) change(rs[nk],rs[k],mid+1,r,x,y,val);
	}
	int ask(int k,int l,int r,int p){
		if (!k) return 0;
		if (l==r) return t[k];
		int mid=(l+r)/2;
		if (p<=mid) return max(t[k],ask(ls[k],l,mid,p));
		else return max(t[k],ask(rs[k],mid+1,r,p));
	}
}
struct AC_automaton{
	int l[N],pos[N],at[N],nd;
	int ch[N][26],fa[N];
	int dfn1[N],ed1[N];
	int dfn2[N],ed2[N];
	map<Hash,int> mp;
	vector<int> ed[N];
	vector<int> e[N]; 
	void ACM(){
		static int q[N];
		int h=0,t=0;
		For(i,0,25)
			if (!ch[1][i]) ch[1][i]=1;
			else{
				fa[ch[1][i]]=1;
				q[++t]=ch[1][i];
			}
		while (h!=t){
			int x=q[++h];
			For(i,0,25)
				if (!ch[x][i])
					ch[x][i]=ch[fa[x]][i];
				else{
					fa[ch[x][i]]=ch[fa[x]][i];
					q[++t]=ch[x][i];
				}
		}
		For(i,2,nd)
			e[fa[i]].PB(i);
	}
	void dfsTR(int x){
		dfn2[x]=(*dfn2)+1;
		for (auto i:ed[x])
			at[i]=++*dfn2;
		For(i,0,25)
			if (ch[x][i])
				dfsTR(ch[x][i]);
		ed2[x]=*dfn2;
	}
	void dfsFA(int x){
		dfn1[x]=++*dfn1;
		for (auto i:e[x]) dfsFA(i);
		ed1[x]=*dfn1;
	}
	void build(){
		nd=1;
		For(i,1,m){
			l[i]=S[i].size();
			Hash tmp(-1);
			int x=1;
			For(j,0,l[i]-1){
				int c=S[i][j];
				tmp=tmp+Hash(c);
				if (!ch[x][c]){
					ch[x][c]=++nd;
					mp[tmp]=nd;
				}
				x=ch[x][c];
			}
			ed[x].PB(i);
			pos[i]=x;
		}
		dfsTR(1);
		ACM();
		dfsFA(1);
	}
	
	int t[N],q[N],rt[N];
	// 
	void TR_change(int x,int v){
		for (;x<=nd;x+=x&(-x)) t[x]+=v;
	}
	int TR_ask(int x){
		int ans=0;
		for (;x;x-=x&(-x)) ans+=t[x];
		return ans;
	}
	void push(int x,Hash tmp){
		q[++*q]=x;
		rt[*q]=rt[(*q)-1];
		if (mp.find(tmp)!=mp.end()){
			int id=mp[tmp];
			SEG::change(rt[*q],rt[*q],1,m,dfn2[id],ed2[id],(*q)-1);
		}
		TR_change(dfn1[x],1);
		//TR_change(ed1[x]+1,-1);
	}
	void pop(){
		assert(*q);
		TR_change(dfn1[q[*q]],-1);
		//TR_change(ed1[q[*q]]+1,1);
		--*q;
	}
	int ask(int x){
		return TR_ask(ed1[pos[x]])-TR_ask(dfn1[pos[x]]-1);
	}
	int askL(int x){
		return SEG::ask(rt[*q],1,m,at[x]);
	}
	void init(){
		*q=0; rt[0]=0;
	}
}AC[2];
namespace TR{
	struct edge{
		int to,next,c;
	}e[N*2];
	int head[N],tot;
	int sz[N],vis[N],rt;
	int co[N],q[N];
	vector<node> op[N];
	void add(int x,int y,int c){
		e[++tot]=(edge){y,head[x],c};
		head[x]=tot;
	}
	void dfs(int x,int fa,int n){
		sz[x]=1; int mx=0;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to]){
				dfs(e[i].to,x,n);
				sz[x]+=sz[e[i].to];
				mx=max(mx,sz[e[i].to]);
			}
		if (sz[x]*2>n&&mx*2<=n)
			rt=x;
	}
	void dfs1(int x,int fa){
		q[++*q]=x;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to]){
				co[e[i].to]=co[x];
				dfs1(e[i].to,x);
			}
	}
	void dfs2(int x,int fa,int p0,int p1,Hash hsh){
		//cout<<x<<' '<<fa<<' '<<p0<<' '<<p1<<' '<<hsh.v1<<endl;
		AC[0].push(p0,hsh);
		AC[1].push(p1,hsh);
		//cout<<x<<' '<<fa<<' '<<p0<<' '<<p1<<endl;
		for (auto i:op[x]){
			ans[i.id]+=AC[i.x^1].ask(i.v);
			L[i.x][i.id]=AC[i.x].askL(i.v);
		}
		//cout<<x<<' '<<fa<<' '<<p0<<' '<<p1<<endl;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to]){
				int np0=AC[0].ch[p0][e[i].c];
				int np1=AC[1].ch[p1][e[i].c];
				Hash nhsh=Hash(e[i].c)+hsh;
				dfs2(e[i].to,x,np0,np1,nhsh);
			}
		AC[0].pop();
		AC[1].pop();
	}
	void solve_prb(int x){
		int low=(*co)++;
		co[x]=*co; q[0]=1; q[1]=x;
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to]){
				co[e[i].to]=++*co;
				dfs1(e[i].to,x);
			}
		//cout<<233<<endl;
		For(i,1,*q)
			for (auto j:vQ[q[i]])
				if (co[j.x]>low&&co[j.x]!=co[q[i]]){
					op[q[i]].PB((node){0,j.v,j.id});
					op[j.x].PB((node){1,j.v,j.id});
				}
		//cout<<233<<endl;
		SEG::init();
		AC[0].init();
		AC[1].init();
		//cout<<233<<endl;
		dfs2(x,0,1,1,Hash(-1));
		For(i,1,*q) op[q[i]].resize(0);
	}
	void solve(int x,int n){
		dfs(x,0,n); vis[x=rt]=1;
		//cout<<x<<' '<<n<<endl;
		solve_prb(x);
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to]) solve(e[i].to,sz[x]<sz[e[i].to]?n-sz[x]:sz[e[i].to]);
	}
}
struct KanMaoPian{
	int dfn[N],ed[N];
	int nx[N],t[N],T;
	vector<int> e[N];
	void dfs(int x){
		dfn[x]=++T;
		for (auto i:e[x]) dfs(i);
		ed[x]=T;
	}
	void TR_change(int x,int v){
		for (;x<=T;x+=x&(-x)) t[x]+=v; 
	}
	int TR_ask(int x){
		int s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
	void change(int x,int v){
		//cout<<x<<' '<<v<<' '<<dfn[x]<<' '<<ed[x]<<endl;
		TR_change(dfn[x],v);
		TR_change(ed[x]+1,-v);
	}
	int ask(int x){
		//cout<<"Q "<<x<<endl;
		return TR_ask(dfn[x]);
	}
	void build(int *a,int n){
		T=0; nx[1]=0;
		For(i,0,n+1) e[i].resize(0);
		For(i,2,n){
			int j=nx[i-1];
			for (;j&&a[j+1]!=a[i];j=nx[j]);
			nx[i]=j+(a[j+1]==a[i]);
		} 
		For(i,1,n){
			//cout<<i<<' '<<nx[i]<<endl;
			e[nx[i]].PB(i);
		}
		dfs(0);
	}
}KMP0,KMP1;
vector<pii> vQQ[N];
vector<int> vec[N];
void dfs(int x,int l){
	if (x&&l-x) KMP1.change(l-x,1);
	for (auto i:vQQ[x]) ans[i.se]+=KMP1.ask(i.fi);
	for (auto i:KMP0.e[x]) dfs(i,l);
	if (x&&l-x) KMP1.change(l-x,-1);
}
void solve(int id){
	static int a[N];
	//cerr<<id<<endl;
	int l=S[id].size();
	For(i,0,l+1) vQQ[i].resize(0);
	For(i,0,l-1) a[i+1]=S[id][i];
	KMP0.build(a,l);
	reverse(a+1,a+l+1);
	KMP1.build(a,l);
	for (auto i:vec[id]){
		if (L[0][i]==l) L[0][i]=KMP0.nx[l];
		if (L[1][i]==l) L[1][i]=KMP1.nx[l];
		//cout<<i<<' '<<id<<' '<<L[0][i]<<' '<<L[1][i]<<endl;
		vQQ[L[0][i]].PB(pii(L[1][i],i));
	}
	dfs(0,l);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d%s",&x,&y,s+1);
		TR::add(x,y,s[1]-'a');
		TR::add(y,x,s[1]-'a');
	}
	//cerr<<233<<endl;
	For(i,1,m){
		scanf("%s",s+1);
		int l=strlen(s+1);
		For(j,1,l) S[i].PB(s[j]-'a');
	}
	//cerr<<233<<endl;
	For(T,0,1){
		AC[T].build();
		For(i,1,m) reverse(S[i].begin(),S[i].end());
	}
	//cerr<<233<<endl;
	For(i,1,Q){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		vQ[x].PB((node){y,z,i});
		type[i]=z;
	}
	TR::solve(1,n);
	//cerr<<233<<endl;
	For(i,1,Q) vec[type[i]].PB(i);
	//cerr<<233<<endl;
	For(i,1,m) solve(i);
	For(i,1,Q) printf("%d\n",ans[i]);
	//For(i,1,Q) cout<<L[0][i]<<' '<<L[1][i]<<endl;
} 
/*
:AC+ 
:
	hash
	LCP
	triedfs 
*/