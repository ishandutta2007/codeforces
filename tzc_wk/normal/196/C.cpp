/*
Contest: -
Problem: Codeforces 196C
Author: tzc_wk
Time: 2020.7.31
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n;
struct point{
	double x,y;
	int id;
} p[1505],ori;
inline bool cmp(point a,point b){
	int ax=a.x-ori.x,ay=a.y-ori.y;
	int bx=b.x-ori.x,by=b.y-ori.y;
	return 1ll*ay*bx<=1ll*ax*by;
}
vector<int> g[1505];
int siz[1505],id[1505];
inline void findsize(int x,int f){
	siz[x]=1;
	foreach(it,g[x]){
		int y=*it;
		if(y==f) continue;
		findsize(y,x);
		siz[x]+=siz[y];
	}
}
inline void dfs(int x,int l,int r,int f){
//	cout<<x<<" "<<ind<<endl;
	int o=l;
	fz(i,l+1,r){
		if(p[i].x<p[o].x||(p[i].x==p[o].x&&p[i].y<p[o].y)) o=i;
	}
	swap(p[o],p[l]);id[p[l].id]=x;ori=p[l];
	sort(p+l+1,p+r+1,cmp);
//	fz(i,l,r) cout<<p[i].x<<" "<<p[i].y<<" ";puts("");
	int cur=l+1;
	foreach(it,g[x]){
		int y=*it;
		if(y==f) continue;
		dfs(y,cur,cur+siz[y]-1,x);
		cur+=siz[y];
	}
}
signed main(){
//	freopen("196C.in","r",stdin);
	n=read();
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fz(i,1,n) p[i].x=read(),p[i].y=read(),p[i].id=i;
	findsize(1,0);
	dfs(1,1,n,0);
	fz(i,1,n) printf("%d ",id[i]);
	return 0;
}