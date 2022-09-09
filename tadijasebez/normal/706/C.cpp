#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int N=100050;
const long long inf=1000000000ll*1000000ll;
vector<char> word[N][2];
char tmp[N];
long long dp[N][2];
int c[N];
bool operator < (vector<char> a, vector<char> b)
{
	int i;
	if(a.size()<b.size())
	{
		for(i=0;i<a.size();i++)
		{
			if(a[i]<b[i]) return true;
			if(a[i]>b[i]) return false;
		}
		return true;
	}
	else
	{
		for(i=0;i<b.size();i++)
		{
			if(a[i]<b[i]) return true;
			if(a[i]>b[i]) return false;
		}
		if(a.size()==b.size()) return true;
		return false;
	}
}
long long min(long long a, long long b){ return a>b?b:a;}
int main()
{
	int n,m,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&tmp);
		m=(unsigned) strlen(tmp);
		for(j=0;j<m;j++) word[i][0].push_back(tmp[j]);
		for(j=m-1;j>=0;j--) word[i][1].push_back(tmp[j]);
	}
	//dp[1][0]=0;
	//dp[1][1]=c[1];
	for(i=1;i<=n;i++)
	{
		dp[i][0]=inf;
		dp[i][1]=inf;
		if(word[i-1][0]<word[i][0]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(word[i-1][1]<word[i][0]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(word[i-1][0]<word[i][1]) dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		if(word[i-1][1]<word[i][1]) dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
		//if(n==44000 && dp[i][0]==inf && dp[i][1]==inf)
		//{
		//	printf("%i ",i);
		//	for(j=0;j<word[i-1][0].size();j++) printf("%c",word[i-1][0][j]);
		//	printf(" ");
		//	for(j=0;j<word[i][0].size();j++) printf("%c",word[i-1][0][j]);
		//	printf("\n");
		//}
	}
	printf("%lld\n",min(dp[n][0],dp[n][1])==inf?-1:min(dp[n][0],dp[n][1]));
	return 0;
}