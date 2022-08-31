//CF1179D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 555555;
LL sq(int x){
	return (LL)x*x;
}
int n,t[N];
vector<int> v[N];
LL f[N],ans;
struct node{
	LL x,y;
	node(LL X=0,LL Y=0){
		x=X,y=Y;
	}
}a[N];
bool operator<(node a,node b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int m,r,p,e[N];
bool cal(int i,int j,int k){
	return (a[j].y-a[i].y)*(a[k].x-a[j].x)>=(a[k].y-a[j].y)*(a[j].x-a[i].x);
}
bool cal2(int i,int j,int k){
	return (a[i].y-a[j].y)<=(a[j].x-a[i].x)*a[k].x*2;
}
void go(int i,int j){
	ans=min(ans,sq(n)+a[i].y+a[j].y+a[i].x*a[j].x*2);
}
void solve(){
	int i;
	sort(a,a+m);
	r=0,p=0;
	for(i=0;i<m;i=i+1){
		while(p>=2&&cal2(e[p-1],e[p],i)){
			p--;
		}
		if(p>0)
			go(i,e[p]);
		while(r>=2&&cal(e[r-1],e[r],i)){
			if(p==r)
				p--;
			e[r--]=0;
		}
		if(p==r)
			p++;
		e[++r]=i;
	}
}
void dfs(int u,int fa){
	int i,x;
	t[u]=1;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		t[u]+=t[x];
	}
	m=0;
	f[u]=sq(t[u]);
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		f[u]=min(f[u],f[x]+sq(t[u]-t[x]));
		ans=min(ans,f[x]+sq(n-t[x]));
		a[m++]=node(t[x],f[x]+sq(t[x])-(LL)n*t[x]*2);
	}
	solve();
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=1e18;
	dfs(1,0);
	cout<<(LL)n*(n-1)-(ans-n)/2;
	return 0;
}