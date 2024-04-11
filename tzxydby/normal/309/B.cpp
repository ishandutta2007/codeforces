#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],nex[N],ans[N],n,r,c,t=1;
char s[6*N];
void dfs(int x)
{
	if(!x)
		return ;
	dfs(x>>1);
	for(int i=1;i<=n;i++)
	{
		ans[i]=ans[ans[i]];
		if(x&1)
			ans[i]=nex[ans[i]];
	}
}
int main()
{
	scanf("%d%d%d",&n,&r,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+a[i]);
		a[i+1]=a[i]+strlen(s+a[i]);
		s[a[i+1]++]=' ';
	}
	for(int i=n+1,j=n+1;i;i--)
	{
		while(a[j]-a[i]>c+1)
			j--;
		nex[ans[i]=i]=j;
	}
	dfs(r);
	for(int i=2;i<=n;i++)
		if(ans[i]-i>ans[t]-t)
			t=i;
	for(int i=1;i<=r;i++,t=nex[t],puts(""))
		for(int j=a[t];j+1<a[nex[t]];j++)
			putchar(s[j]);
	return 0;
}