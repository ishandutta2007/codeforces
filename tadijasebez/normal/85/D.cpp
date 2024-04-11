#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=100050;
const int M=2*N;
vector<int> id;
int sum[M];
ll dp[M][5];
int ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	int i;
	if(!c) c=++clock;
	if(ss==se)
	{
		sum[c]+=val;
		for(i=0;i<5;i++) dp[c][i]=0;
		dp[c][0]=id[ss-1]*sum[c];
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	sum[c]=sum[ls[c]]+sum[rs[c]];
	for(i=0;i<5;i++) dp[c][i]=dp[ls[c]][i]+dp[rs[c]][(i-sum[ls[c]]%5+5)%5];
}
char s[N][10];
int x[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&s[i]);
		if(s[i][0]!='s') scanf("%i",&x[i]),id.push_back(x[i]);
	}
	sort(id.begin(),id.end());
	for(i=1;i<=n;i++)
	{
		if(s[i][0]=='s') printf("%lld\n",dp[root][2]);
		else if(s[i][0]=='a') Set(root,1,id.size(),lower_bound(id.begin(),id.end(),x[i])-id.begin()+1,1);
		else Set(root,1,id.size(),lower_bound(id.begin(),id.end(),x[i])-id.begin()+1,-1);
	}
	return 0;
}