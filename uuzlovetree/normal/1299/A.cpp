#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int id,pre[100005],suf[100005],ans[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]|a[i];
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]|a[i];
	for(int i=1;i<=n;++i)
	{
		int x=pre[i-1]|suf[i+1];
		ans[i]=(a[i]|x)-x;
	}
	int id=1;
	for(int i=1;i<=n;++i)if(ans[i]>ans[id])id=i;
	swap(a[id],a[1]); 
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
}