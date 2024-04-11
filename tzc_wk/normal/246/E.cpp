#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
int n,qu,c[MAXN+5],rt,idnum=0;map<string,int> id;
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct query{int x,k,id;} q[MAXN+5];
vector<int> qv[MAXN+5];
int siz[MAXN+5],wson[MAXN+5],dep[MAXN+5];
void dfs0(int x,int f){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
set<int> st[MAXN+5];
int ans[MAXN+5];
void del(int x,int f){
	if(st[dep[x]].find(c[x])!=st[dep[x]].end())
		st[dep[x]].erase(st[dep[x]].find(c[x]));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;del(y,x);
	}
}
void add(int x,int f){
	st[dep[x]].insert(c[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;add(y,x);
	}
}
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		dfs(y,x);del(y,x);
	} if(wson[x]) dfs(wson[x],x);
	st[dep[x]].insert(c[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		add(y,x);
	}
	ffe(it,qv[x]){int id=*it;ans[q[id].id]=st[dep[x]+q[id].k].size();}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string s;int f;cin>>s>>f;
		if(!id[s]) id[s]=++idnum;
		c[i]=id[s];adde(f,i);
	} scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		scanf("%d%d",&q[i].x,&q[i].k);q[i].id=i;
		qv[q[i].x].pb(i);
	} dfs0(0,0);dfs(0,0);
	for(int i=1;i<=qu;i++) printf("%d\n",ans[i]);
	return 0;
}