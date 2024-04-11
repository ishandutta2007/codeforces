#include <bits/stdc++.h>
#define Maxn 500007
using namespace std;
int n,m,p,now,cnt=0;
int last[Maxn],next[Maxn],a[Maxn];
int que[Maxn];
char ch[Maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	scanf("%s",ch);
	memset(a,0,sizeof(a));
	memset(que,0,sizeof(que));
	for (int i=0;i<n;i++)
	{
		if (ch[i]=='(') que[++cnt]=i+1;
		else
		{
			a[i+1]=que[cnt];
			a[que[cnt]]=i+1;
			--cnt;
		}
	}
	next[0]=1,last[n+1]=n;
	for (int i=1;i<=n;i++)
		last[i]=i-1,next[i]=i+1;
	now=0;
	while (p--) now=next[now];
	while (m--)
	{
		char op=getchar();
		while (op!='R'&&op!='L'&&op!='D') op=getchar();
		if (op=='R') now=next[now];
		else if (op=='L') now=last[now];
		else
		{
			int x=min(a[now],now),y=max(a[now],now);
			next[last[x]]=next[y];
			last[next[y]]=last[x];
			now=next[y];
			if (now>n) now=last[now];
		}
	}
	now=next[0];
	while (now<=n)
	{
		printf("%c",ch[now-1]);
		now=next[now];
	}
	printf("\n");
	return 0;
}