#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,k;
int c[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	int maxv=0;
	for(int x,i=1;i<=n;++i)
	{
		scanf("%d",&x);
		c[x]++;
		maxv=max(maxv,c[x]);
	}
	int t=0;
	if(maxv%k==0)t=maxv/k;
	else t=maxv/k+1;
	t=t*k;
	int ans=0;
	for(int i=1;i<=100;++i)if(c[i])ans+=t-c[i];
	cout<<ans<<endl;
	return 0;
}