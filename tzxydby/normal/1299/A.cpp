#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],pre[N],suf[N],ans,p,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]|a[i];
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]|a[i];
	ans=(a[1]|suf[2])-suf[2],p=1;
	for(int i=2;i<=n;i++)
	{
		int k=pre[i-1]|suf[i+1];
		int t=(a[i]|k)-k;
		if(t>ans)
		{
			ans=t;
			p=i;
		}
	}
	printf("%d ",a[p]);
	for(int i=1;i<=n;i++)
		if(i!=p)
			printf("%d ",a[i]);
	return 0;
}