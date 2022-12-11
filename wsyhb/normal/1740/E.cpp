#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int p[max_n],dp[max_n],mx_dep[max_n];
vector<int> son[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",p+i);
		son[p[i]].push_back(i);
	}
	for(int x=n;x>=1;--x)
	{
		mx_dep[x]=1;
		for(int y:son[x])
			mx_dep[x]=max(mx_dep[x],mx_dep[y]+1);
	}
	for(int x=n;x>=1;--x)
	{
		int sum=0;
		for(int y:son[x])
			sum+=dp[y];
		dp[x]=max(sum,mx_dep[x]);
	}
	printf("%d\n",dp[1]);
	return 0;
}