//CF 314E
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
typedef unsigned int uint;
const int N = 111111;
int n,a[N];
char ch[N];
uint dp[N];
int main()
{
	int i,j,l=0;
	scanf("%d%s",&n,ch+1);
	//n=1e5;
	for(i=1;i<=n;i=i+1)
		a[i]=ch[i]=='?',l+=a[i];
	dp[1]=1;
	for(i=n/2;i<l;i=i+1)
		dp[1]=dp[1]*25;
	for(i=1;i<=n;i=i+1){
		l=min(i,n-i)+2;
		for(j=1+(i&1^1);j<=l;j+=2){
			dp[j+1]+=dp[j];
			if(a[i])
				dp[j-1]+=dp[j];
			dp[j]=0;
		}
	}
	cout<<dp[1];
	return 0;
}