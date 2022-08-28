//CF1572C
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
const int N = 3333;
int n,a[N],f[N][N];
vector<int> v[N];
int solve(int l,int r){
	if(f[l][r]>=0)
		return f[l][r];
	if(r-l<=1)
		return f[l][r]=0;
	f[l][r]=solve(l+1,r);
	int i,x;
	for(i=0;i<v[a[l]].size();i++){
		x=v[a[l]][i];
		if(l<x&&x<=r)
			f[l][r]=max(f[l][r],solve(l+1,x-1)+solve(x,r)+1);
	}
	return f[l][r];
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		n=unique(a+1,a+n+1)-a-1;
		for(i=1;i<=n;i++)
			v[a[i]].push_back(i);
		for(i=0;i<=n+1;i++)
			for(j=0;j<=n+1;j++)
				f[i][j]=-1;
		printf("%d\n",n-1-solve(1,n));
		for(i=1;i<N;i++)
			v[i].clear();
	}
	return 0;
}