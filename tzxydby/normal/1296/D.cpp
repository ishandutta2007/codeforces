#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int h[N],n,a,b,k;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		h[i]=(h[i]-1)%(a+b)+1;
		h[i]=(h[i]+a-1)/a-1;
	}
	int ans=0;
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++)
	{
		if(k>=h[i])
		{
			k-=h[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}