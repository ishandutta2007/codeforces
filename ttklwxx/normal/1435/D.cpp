#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[200001],qr;
int opt[200001],sl[200001];
priority_queue<int,vector<int>,greater<int> >que;
int main()
{
	int n;
	char s[10];
	n=read();
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",s+1);
		if(s[1]=='+')
		{
			a[++qr]=i;
			opt[i]=1;
		}
		else
		{
			opt[i]=2;
			sl[i]=read();
			if(qr==0)
			{
				printf("NO\n");
				return 0;
			}
			sl[a[qr--]]=sl[i];
		}
	}
	for(int i=1;i<=2*n;i++)
	{
		if(opt[i]==1)
		{
			que.push(sl[i]);
		}
		else
		{
			if(que.top()!=sl[i])
			{
				printf("NO\n");
				return 0;
			}
			que.pop();
		}
	}
	printf("YES\n");
	for(int i=1;i<=2*n;i++)if(opt[i]==1)printf("%d ",sl[i]);
	return 0;
}