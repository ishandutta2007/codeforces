//CF 900E
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
const int N = 111111;
char ch[N];
int n,t,sa[N][2],sb[N][2],ss[N];
int dp[N],f[N];
int cost(int r){
	int l;
	l=r-t;
	if(l<0)
		return -1;
	if(sb[r][l&1^1]-sb[l][l&1^1])
		return -1;
	if(sa[r][l&1]-sa[l][l&1])
		return -1;
	return ss[r]-ss[l];
}
int main()
{
	int i,j;
	scanf("%d%s%d",&n,ch+1,&t);
	for(i=1;i<=n;i=i+1){
		j=i&1;
		if(ch[i]=='a')
			sa[i][j]++;
		if(ch[i]=='b')
			sb[i][j]++;
		if(ch[i]=='?')
			ss[i]++;
		for(j=0;j<=1;j=j+1){
			sa[i][j]+=sa[i-1][j];
			sb[i][j]+=sb[i-1][j];
		}
		ss[i]+=ss[i-1];
	}
	for(i=1;i<=n;i=i+1){
		dp[i]=dp[i-1],f[i]=f[i-1];
		j=cost(i);
		if(j<0)
			continue;
		if(dp[i]==dp[i-t]+1)
			f[i]=min(f[i],f[i-t]+j);
		if(dp[i]<dp[i-t]+1)
			dp[i]=dp[i-t]+1,f[i]=f[i-t]+j;
	}
	cout<<f[n]<<endl;
	return 0;
}