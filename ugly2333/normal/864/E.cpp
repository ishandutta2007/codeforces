//CF 864E
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
const int N = 111;
const int D = 2222;
const int d = 2017;
struct node{
	int t;
	int d;
	int v;
	int id;
}a[N];
bool cmp(node x,node y){
	return x.d<y.d;
}
int dp[N][D],f[N][D];
int s[N];
int main()
{
	int n,i,j,k,ans;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i].t>>a[i].d>>a[i].v;
		a[i].d--;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=d;j=j+1){
			if(j>=a[i].t&&j<=a[i].d&&dp[i-1][j-a[i].t]+a[i].v>dp[i-1][j]){
				dp[i][j]=dp[i-1][j-a[i].t]+a[i].v;
				f[i][j]=j-a[i].t;
			}
			else{
				dp[i][j]=dp[i-1][j];
				f[i][j]=j;
			}
			if(dp[i][j]<dp[i][j-1]){
				dp[i][j]=dp[i][j-1];
				f[i][j]=f[i][j-1];
			}
			//cout<<dp[i][j]<<' ';
		}
		//cout<<endl;
	}
	cout<<dp[n][d]<<endl;
	j=d;
	ans=0;
	for(i=n;i>=1;i=i-1){
		k=f[i][j];
		if(dp[i-1][k]<dp[i][j]){
			ans++;
			s[ans]=a[i].id;
		}
		j=k;
	}
	cout<<ans<<endl;
	reverse(s+1,s+ans+1);
	for(i=1;i<=ans;i=i+1)
		cout<<s[i]<<' ';
	return 0;
}