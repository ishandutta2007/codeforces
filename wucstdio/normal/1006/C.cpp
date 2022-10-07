#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
LL n,d[200005],ans;
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&d[i]);
		d[i]+=d[i-1];
	}
	LL l=1,r=n;
	while(l<r)
	{
		if(d[l]<d[n]-d[r-1])l++;
		else if(d[l]>d[n]-d[r-1])r--;
		else ans=max(ans,d[l]),l++,r--;
	}
	printf("%I64d\n",ans);
	return 0;
}