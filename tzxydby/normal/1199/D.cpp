#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],ls[N],s[N],n,q;
int suf[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ls[i]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{ 
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int p,x;
			scanf("%d%d",&p,&x);
			a[p]=x; 
			ls[p]=i;
		}
		else
			scanf("%d",&suf[i]);
	}
	for(int i=q;i>=1;i--)
		suf[i]=max(suf[i],suf[i+1]);
	for(int i=1;i<=n;i++)
		printf("%d ",max(a[i],suf[ls[i]]));
	return 0;
}