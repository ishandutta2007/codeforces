/*
Contest: Codeforces Round #664 (Div.1)
Problem: Codeforces 1394B
Author: tzc_wk
Time: 2020.8.12
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(ll i=a;i<=b;i++)
#define fd(i,a,b)	for(ll i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read(),k=read();
struct edge{
	int to,c;
	edge(){}
	edge(int _to,int _c){to=_to;c=_c;}
	friend bool operator <(edge a,edge b){
		return a.c<b.c;
	}
};
vector<edge> g[200005],rev[200005];
map<int,int> rk[200005];
int deg[200005];
long long taboo[46];
int id[10][10],icnt=0,p[10];
int ans=0;
bool vis[46],invalid[46];
inline void dfs(int x){
	if(x==k+1){
//		fz(i,1,k) cout<<p[i]<<" ";puts("");
		ans++;return;
	}
	fz(i,1,x){
		int t=id[x][i];
		if(invalid[t]) continue;
		bool flg=1;
		fz(j,1,t) if(vis[j]&&(taboo[t]>>(j-1ll)&1)) flg=0;
		if(flg){
			vis[t]=1;p[x]=i;dfs(x+1);p[x]=0;vis[t]=0;
		}
	}
}
signed main(){
	fz(i,1,k) fz(j,1,i) id[i][j]=++icnt;
	fz(i,1,m){
		int u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		rev[v].push_back(edge(u,w));
		deg[u]++;
	}
	fz(i,1,n) sort(g[i].begin(),g[i].end());
	fz(i,1,n) for(int j=0;j<g[i].size();j++) rk[i][g[i][j].to]=j+1;
	fz(i,1,n){
		set<int> st;
		long long msk=0;
		foreach(it,rev[i]){
			int j=it->to;
			int t=rk[j][i];
			int d=deg[j];
			if(st.find(id[d][t])!=st.end()) invalid[id[d][t]]=1;
//			cout<<"{"<<d<<","<<t<<"}"<<" ";
			msk|=(1ll<<(id[d][t]-1));
			st.insert(id[d][t]);
		}
//		puts("");
		foreach(it,st) taboo[*it]|=msk;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
3 6 2
1 2 1
2 1 2
3 2 3
1 3 4
2 3 5
3 1 6

5 19 4
1 2 1
1 3 2
1 4 3
1 5 4
2 1 5
2 3 6
2 4 7
2 5 8
3 1 9
3 2 10
3 4 11
3 5 12
4 1 13
4 2 14
4 3 15
4 5 16
5 1 17
5 2 18
5 3 19
*/