#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n;
char s[maxn];
int a[maxn];
int cnt;
stack<int> stk;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0,tot=1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')stk.push(i);
		else
		{
			if(stk.empty())a[++cnt]=i;
			else stk.pop();
		}
	}
	while(!stk.empty())
	{
		int x=stk.top();
		stk.pop();
		a[++cnt]=x;
	}
	a[++cnt]=n+1;
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;++i)
	{
		int t=a[i]-a[i-1]-1;
		if(t==ans)tot++;
		if(t>ans)ans=t,tot=1;
	}
	if(!ans)tot=1;
	printf("%d %d\n",ans,tot);
	return 0;
}