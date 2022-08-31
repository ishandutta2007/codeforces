//CF1616A
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
const int N = 111;
const DB eps = 1e-9;
int n,a[N];
int solve(int l,int r){
	DB k=(DB)(a[r]-a[l])/(DB)(r-l);
	int i,o=0;
	for(i=1;i<=n;i++)
		if(fabs(k*(i-l)+a[l]-a[i])<eps)
			o++;
	return o;
}
int main()
{
	int T,i,j,x,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		s=1;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				s=max(s,solve(i,j));
		printf("%d\n",n-s);
	}
	return 0;
}