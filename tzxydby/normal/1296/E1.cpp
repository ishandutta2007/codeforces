#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,p=1,ans[N],zyb[N],out[N];
char s[N];
void co(int l,int r)
{
	int co=-1;
	for(int i=l;i<r;i++)
	{
		if(ans[i]!=-1)
		{
			if(co==-1)
				co=ans[i];
			else if(co!=ans[i])
			{
				puts("NO");
				exit(0);
			}
		}
	}
	if(ans[r]!=-1&&ans[r]==co)
	{
		puts("NO");
		exit(0);
	}
	if(co==-1)
		co=0;
	for(int i=l;i<r;i++)
		ans[i]=co;
	ans[r]=co^1;
	for(int i=r;i>l;i--)
		swap(s[i],s[i-1]),swap(ans[i],ans[i-1]),swap(zyb[i],zyb[i-1]);
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		ans[i]=-1,zyb[i]=i;
	for(int i=0;i<26;i++)
	{
		while(s[p]==i+'a')
			ans[p]=0,p++;
		for(int j=p;j<=n;j++)
		{
			if(s[j]==i+'a')
			{
				co(p,j);
				p++;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		out[zyb[i]]=ans[i];
	for(int i=1;i<=n;i++)
		printf("%d",out[i]);
	return 0;
}