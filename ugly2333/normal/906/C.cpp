//CF 906C
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
#include<ctime>
using namespace std;
typedef long long LL;
const int N = 25;
const int M = 1<<23;
int n,a[N],f[M],g[M];
int dfs(int x){
	if(f[x])
		return f[x];
	int i,t,ff=N,gg=-1;
	f[x]=N;
	for(i=0;i<n;i=i+1)
		if(x&(1<<i)){
			t=dfs(x|a[i])+1;
			if(t<ff)
				ff=t,gg=i;
		}
	f[x]=ff,g[x]=gg;
	//cout<<x<<' '<<f[x]<<endl;
	return f[x];
}
void prt(int x){
	if(g[x]<0)
		return;
	cout<<g[x]+1<<' ';
	prt(x|a[g[x]]);
}
int main()
{
	int m,x,y,i,t,ff,gg;
	cin>>n>>m;
	if(m==n*(n-1)/2){
		cout<<0<<endl;
		return 0;
	}
	while(m--){
		cin>>x>>y;
		x--,y--;
		a[x]|=1<<y;
		a[y]|=1<<x;
	}
	m=1<<n;
	f[m-1]=1,g[m-1]=-1;
	ff=N,gg=0;
	for(i=0;i<n;i=i+1){
		t=dfs(1<<i);
		if(t<ff)
			ff=t,gg=i;
	}
	ff--;
	cout<<ff<<endl;
	prt(1<<gg);
	return 0;
}