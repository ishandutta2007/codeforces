#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt,now,ans;
int dfn[300005],rnk[300005],siz[300005];
vector<int> adj1[300005],adj2[300005];
set<int> st;

void dfs1(int u){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(auto v:adj2[u]) dfs1(v),siz[u]+=siz[v];
}

void add(int u){
	st.insert(dfn[u]);
	auto it=st.lower_bound(dfn[u]);
	if(it==st.begin()) return (void)(now++);
	auto it1=it; it1--;
	if(dfn[u]>*it1+siz[rnk[*it1]]-1) return (void)(now++);
	auto it2=it; it2++;
	if(it2==st.end()) return;
	if(*it2<=*it1+siz[rnk[*it1]]-1) return (void)(now++);
}

void del(int u){
	st.erase(dfn[u]);
	auto it=st.lower_bound(dfn[u]);
	if(it==st.begin()) return (void)(now--);
	auto it1=it; it1--;
	if(dfn[u]>*it1+siz[rnk[*it1]]-1) return (void)(now--);
	if(it==st.end()) return;
	if(*it<=*it1+siz[rnk[*it1]]-1) return (void)(now--);
}

void dfs2(int u){
	add(u);
	chkmax(ans,now);
	for(auto v:adj1[u]) dfs2(v);
	del(u);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) adj1[i].clear(),adj2[i].clear();
		ncnt=0;
		for(int i=1;i<n;i++) adj1[readint()].pb(i+1);
		for(int i=1;i<n;i++) adj2[readint()].pb(i+1);
		dfs1(1);
		st.clear(),now=ans=0;
		dfs2(1);
		printf("%d\n",ans);
	}
	return 0;
}