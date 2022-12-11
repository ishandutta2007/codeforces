#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int n,k;
const int N=2e5+5;
int a[N],ans1[N<<1],ans2[N<<1];//ans1: ans2: 
void work(int x,int y)
{
	int a=min(x,y)+1,b=max(x,y)+k;
	ans1[a]++,ans1[b+1]--;
	ans2[x+y]++;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		for(int i=1;i<=(n>>1);i++) work(a[i],a[n-i+1]);
		k<<=1;
		int ans=0;
		for(int i=1;i<=k;i++)
		{
			ans1[i]+=ans1[i-1];
			ans=max(ans,ans1[i]+ans2[i]);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}