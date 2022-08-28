// CF 846F
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
const int N = 1111111;
int a[N];
vector<int> v[N];
int main()
{
	int n,i,j,s;
	LL ans;
	double d;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		v[a[i]].push_back(i);
	}
	ans=0;
	for(i=1;i<=1000005;i=i+1){
		s=v[i].size();
		if(!s)
			continue;
		ans+=(LL)n*n;
		ans-=(LL)(v[i][0]-1)*(v[i][0]-1);
		for(j=1;j<s;j=j+1)
			ans-=(LL)(v[i][j]-v[i][j-1]-1)*(v[i][j]-v[i][j-1]-1);
		ans-=(LL)(n-v[i][s-1])*(n-v[i][s-1]);
	}
	d=(double)1/n;
	d=(double)d*ans;
	printf("%.9lf",(double)d/n);
	return 0;
}