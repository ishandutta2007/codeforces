#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int a[max_n],b[max_n],from[max_n],st[max_n],tp;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	int R=n;
	for(int i=n;i>=1&&R;--i)
	{
		if(i<R)
			break;
		int s=i+b[i];
		int x=s-a[s];
		while(R>x)
			from[--R]=i;
	}
	if(R==0)
	{
		int now=0;
		while(now!=n)
		{
			st[++tp]=now;
			now=from[now];
		}
		printf("%d\n",tp);
		for(int i=tp;i>=1;--i)
			printf("%d%c",st[i],i>1?' ':'\n');
	}
	else
		puts("-1");
	return 0;
}