#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


using namespace std;
#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> VI;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}


const int N = 150050;
int n,m,k,s[N],t[N],lc[N],u,v;
vector<int> G[N],G2[N],T[N],oT[N];

int fa[N][19],d[N],dfn[N],sz[N],tim = 0;
void dfs0(int num,int cf = 0){
	dfn[num] = ++tim;
	fa[num][0] = cf;
	sz[num] = 1;
	for(int j=0;fa[num][j];j++)fa[num][j+1] = fa[fa[num][j]][j];
	for(auto ct:G[num]){
		if(ct==cf)continue;
		d[ct] = d[num]+1;
		dfs0(ct,num);
		sz[num]+=sz[ct];
	}
}

inline int lca(int u,int v){
	if(d[u]<d[v])swap(u,v);
	for(int i=18;i>=0;i--)if(fa[u][i] && d[fa[u][i]]>=d[v])u = fa[u][i];
	for(int i=18;i>=0;i--)if(fa[u][i]!=fa[v][i])u = fa[u][i],v = fa[v][i];
	return u == v?u:fa[u][0];
}

inline int anc(int u,int x){
	for(int i=18;i>=0;i--) if(fa[u][i] && d[fa[u][i]]>=x)u = fa[u][i];
	return u;
}

struct Fenwick{
	int s[N];
	vector<pii> log;
	inline void update(int pos, int dif) {
		log.emplace_back(pos,dif);
		while(pos<N){
			s[pos]+=dif;
			pos+=pos&(-pos);
		}
	}
	void reset(){
		int pos,dif;
		for(auto ct:log){
			pos = ct.F;
			dif = -ct.S;
			while(pos<N){
				s[pos]+=dif;
				pos+=pos&(-pos);
			}
		}
		log.clear();
	}
	inline int query(int pos) {
		int res = 0;
		while(pos){
			res+=s[pos];
			pos-=pos&(-pos);
		}
		return res;
	}
}A;

vector<pii> F[N],F2[N];

struct node{
	int ls = 0,rs = 0;
	int val = 0;
}nds[10000010];
int cnt = 0,rts[N];
#define mid ((cl+cr)/2)
int query(int id,int l,int r,int cl = 0,int cr = n){
	if(id == 0)return 0;
	if(l<=cl && cr<=r)return nds[id].val;
	int ans = 0;
	if(l<=mid)ans+=query(nds[id].ls,l,r,cl,mid);
	if(r>mid)ans+=query(nds[id].rs,l,r,mid+1,cr);
	return ans;
}
void add(int id,int x,int cl = 0,int cr = n){
	nds[id].val++;
	if(cl == cr)return;
	if(x<=mid){
		if(!nds[id].ls)nds[id].ls = ++cnt;
		add(nds[id].ls,x,cl,mid);
	}else{
		if(!nds[id].rs)nds[id].rs = ++cnt;
		add(nds[id].rs,x,mid+1,cr);
	}
}
int merge(int a,int b){
	if(!a || !b)return a|b;
	nds[a].val+=nds[b].val;
	nds[a].ls = merge(nds[a].ls,nds[b].ls);
	nds[a].rs = merge(nds[a].rs,nds[b].rs);
	return a;
}

void reset(){
	memset(nds,0,sizeof(nds[0])*(cnt+1));
	cnt = 0;
}
ll ans = 0;

int crt = 0;
void dfs1(int num){
	int tgt;
	auto add_it = [&](int ct){
		if(d[num]+d[ct]-2*d[crt]>=k){
			if(d[num]>=d[crt]+k){
				tgt = anc(num,d[num]-k+1);
				ans+=nds[rts[num]].val;
				ans-=query(rts[num],dfn[tgt],dfn[tgt]+sz[tgt]-1);
			}else{
				tgt = anc(ct,d[crt]+k-(d[num]-d[crt]));
				ans +=query(rts[num],dfn[tgt],dfn[tgt]+sz[tgt]-1);
			}
		}
	};
	int mx = -1,ms = -1;
	for(auto ech:G2[num]){
		dfs1(ech);
		if((int)T[ech].size()>mx){
			mx = T[ech].size();
			ms = ech;
		}
	}
	if(ms!=-1)rts[num] = merge(rts[num],rts[ms]);
	for(auto ct:T[num]){
		add_it(ct);
		add(rts[num],dfn[ct]);
	}
	if(ms!=-1){
		//cout<<ms<<endl;
		swap(T[num],T[ms]);
		for(auto ct:T[ms])T[num].PB(ct);
	}
	for(auto ech:G2[num]){
		if(ech == ms){
			//cout<<"JMP"<<endl;
			continue;
		}
		for(auto ct:T[ech]){
			add_it(ct);
			T[num].PB(ct);
		}
		rts[num] = merge(rts[num],rts[ech]);
	}
}

int main() {
	read(n,m,k);
	for(int i=1;i<n;i++){
		read(u,v);
		G[u].PB(v);
		G[v].PB(u);
	}
	d[1] = 1;
	dfs0(1);
	for(int i=0;i<m;i++){
		read(s[i],t[i]);
		if(dfn[s[i]]>dfn[t[i]])swap(s[i],t[i]);
		lc[i] = lca(s[i],t[i]);
		F[d[lc[i]]].emplace_back(s[i],t[i]);
		F2[lc[i]].emplace_back(s[i],t[i]);
	}
	for(int i=n;i>=1;i--){
		for(auto ct:F[i]){
			int l = ct.F,r = ct.S;
			ans+=A.query(dfn[l]);
			ans+=A.query(dfn[r]);
		}
		for(auto ct:F[i]){
			int l = ct.F,r = ct.S;
			if(d[l]>=i+k){
				l = anc(l,i+k);
				A.update(dfn[l],1);
				A.update(dfn[l]+sz[l],-1);
			}
			if(d[r]>=i+k){
				r = anc(r,i+k);
				A.update(dfn[r],1);
				A.update(dfn[r]+sz[r],-1);
			}
		}
	}
	A.reset();
	auto cmp = [&](int a,int b)->bool{return dfn[a]<dfn[b];};
	for(int i=1;i<=n;i++){
		crt = i;
		vector<int> cu,scope;
		scope.PB(i);
		for(auto ct:F2[i]){
			cu.PB(ct.F);
			T[ct.F].PB(ct.S);
			oT[ct.F].PB(ct.S);
		}
		sort(all(cu),cmp);
		cu.erase(unique(all(cu)),cu.end());
		vector<int> stk;
		stk.PB(i);
		rts[i] = ++cnt;
		auto pb = [&](int a){
			rts[a] = ++cnt;
			scope.PB(a);
			stk.PB(a);
		};
		for(auto ct:cu){
			int dd = lca(ct,stk.back());
			while(d[stk.back()]>d[dd]){
				if(d[stk[stk.size()-2]]>d[dd]) G2[stk[stk.size()-2]].PB(stk.back());
				else G2[dd].PB(stk.back());
				stk.pop_back();
			}
			if(d[stk.back()]<d[dd]) pb(dd);
			if(d[stk.back()]<d[ct]) pb(ct);
		}
		while(stk.size()>=2){
			G2[stk[stk.size()-2]].PB(stk.back());
			stk.pop_back();
		}
		dfs1(i);
		for(auto ct:cu){
			ans+=1ll*A.query(dfn[ct])*oT[ct].size();
			for(auto ed:oT[ct]){
				if(d[ed]>=d[i]+k){
					int cc = anc(ed,d[i]+k);
					A.update(dfn[cc],1);
					A.update(dfn[cc]+sz[cc],-1);
				}
			}
		}
		A.reset();
		reset();
		for(auto ct:scope){
			G2[ct].clear();
			rts[ct] = 0;
			T[ct].clear();
			oT[ct].clear();
		}
	}
	cout<<ans<<endl;
	return 0;
}