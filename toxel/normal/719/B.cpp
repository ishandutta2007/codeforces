#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main()
{
	int n,i,cb,cr,ans;
	char s[N];
	scanf("%d",&n);
	scanf("%s",s);
	cb=0;
	cr=0;
	for (i=0;i<n;i++)
	{
		if (i%2)
		{
			if (s[i]=='r')
				cb++;
		}
		else
		{
			if (s[i]=='b')
				cr++;
		}
	}
	ans=max(cb,cr);
	cb=0;
	cr=0;
	for (i=0;i<n;i++)
	{
		if (i%2)
		{
			if (s[i]=='b')
				cr++;
		}
		else
		{
			if (s[i]=='r')
				cb++;
		}
	}
	ans=min(ans,max(cb,cr));
	printf("%d",ans);
	return 0;
}