//
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 32;
int n,u,r,a[N][N],b[N],p[N],k[N];
LL ans=-1e18;
void dfs(int x,bool z){
	int i;
	if(x%2==u%2){
		LL t=0;
		for(i=1;i<=n;i=i+1)
			t+=(LL)a[i][x]*k[i];
		ans=max(ans,t);
	}
	if(x>=u)
		return;
	for(i=1;i<=n;i=i+1)
		a[i][x+1]=a[p[i]][x]+r;
	dfs(x+1,1);
	if(z){
		for(i=1;i<=n;i=i+1)
			a[i][x+1]=a[i][x]^b[i];
		dfs(x+1,0);
	}
}
int main()
{
	int i,j;
	cin>>n>>u>>r;
	for(i=1;i<=n;i=i+1)
		cin>>a[i][0];
	for(i=1;i<=n;i=i+1)
		cin>>b[i];
	for(i=1;i<=n;i=i+1)
		cin>>k[i];
	for(i=1;i<=n;i=i+1)
		cin>>p[i];
	dfs(0,1);
	cout<<ans;
	return 0;
}