//CF 571B
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
const int N = 333333;
const int K = 5005;
int a[N];
LL dp[K][K];
int main()
{
	int n,k,i,j,x,y,f,g,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i=i+1)
		scanf("%d",a+i);
	sort(a,a+n);
	f=n/k+1;
	g=n/k;
	x=n%k;
	y=k-x;
	for(i=0;i<=x;i=i+1)
		for(j=0;j<=y;j=j+1){
			t=f*i+g*j-1;
			if(i||j)
				dp[i][j]=(LL)1<<59;
			if(i)
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[t]-a[t-f+1]);
			if(j)
				dp[i][j]=min(dp[i][j],dp[i][j-1]+a[t]-a[t-g+1]);
			//cout<<dp[i][j]<<endl;
		}
	cout<<dp[x][y]<<endl;
	return 0;
}