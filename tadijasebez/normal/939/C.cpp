#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int dp[N],a[N],n,b[N];
int sum(int l, int r)
{
	//if(l-r==1) return dp[n];
	//if(l>r) return dp[n]-sum(r+1,l-1);
	return dp[r]-dp[l-1];
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int s,t,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i]=dp[i-1]+a[i];
	scanf("%i %i",&s,&t);
	int len=t-s;
	int sol=-1;
	for(i=1;i<=n;i++)
	{
		int p=i+len-n-1;
		b[i]=sum(i,min(i+len-1,n))+sum(1,max(p,0));
		//printf("%i ",b[i]);
	}
	t--;
	vector<int> ret;
	for(i=1;i<=n;i++)
	{
		if(sol<b[i]) sol=b[i],ret.clear();
		if(sol==b[i]) ret.push_back(i);
	}
	for(i=0;i<ret.size();i++)
	{
		ret[i]=(s-ret[i]+1+n)%n;
		if(!ret[i]) ret[i]=n;
	}
	sort(ret.begin(),ret.end());
	printf("%i\n",ret[0]);
	/*for(i=1;i<=n;i++)
	{
		int p=i+len-n-1;
		int ans=sum(i,min(n,i+len-1))+sum(1,max(p,0));
		if(sol==ans) ret.push_back(i);
		else if(sol<ans) sol=ans,ret.clear(),ret.push_back(i);
	}
	for(i=0;i<ret.size();i++)
	{
		ret[i]+=s;
		ret[i]%=n;
		if(ret[i]==0) ret[i]=n;
	}
	sort(ret.begin(),ret.end());
	printf("%i\n",ret[0]);*/
	return 0;
}