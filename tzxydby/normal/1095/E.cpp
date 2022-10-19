#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,ans,a[N],b[N];
char st[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+((st[i]=='(')?1:-1);
		if(a[i-1]==-1) 
			a[i]=-1;
	}
	for(int i=n;i>=1;i--)
	{
		b[i]=b[i+1]+((st[i]==')')?1:-1);
		if(b[i+1]==-1) 
			b[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==')'&&b[i+1]>=1&&a[i-1]>=0&&b[i+1]-1==a[i-1]) 
			ans++;
		if(st[i]=='('&&a[i-1]>=1&&b[i+1]>=0&&a[i-1]-1==b[i+1]) 
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}