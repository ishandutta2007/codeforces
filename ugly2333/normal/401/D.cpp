//CF 401D
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
const int N = 22;
const int M = 105;
int n,m,a[N];
LL dp[1<<19][M];
int main()
{
	int i,j,k,f;
	LL t;
	scanf("%lld%d",&t,&m);
	n=0;
	while(t){
		a[n++]=t%10;
		t/=10;
	}
	dp[0][0]=1;
	for(i=0;i<(1<<n);i=i+1){
		f=0;
		for(j=0;j<n;j=j+1){
			if(i&(1<<j)||f&(1<<a[j]))
				continue;
			if(!i&&!a[j])
				continue;
			f^=(1<<a[j]);
			for(k=0;k<m;k=k+1)
				dp[i^(1<<j)][(k*10+a[j])%m]+=dp[i][k];
		}
	}
	i=1<<n;
	cout<<dp[i-1][0]<<endl;
	return 0;
}