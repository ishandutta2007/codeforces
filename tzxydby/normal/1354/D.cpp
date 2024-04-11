#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int b[N],n,q;
int add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int sum(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x,1);
	}
	while(q--)
	{
		int x;
		scanf("%d",&x);
		if(x>0)
			add(x,1);
		else
		{
			x=-x;
			int l=1,r=n,ans=0;
			while(l<=r)
			{
				int m=l+r>>1;
				if(sum(m)<x)
					l=m+1;
				else
					r=m-1,ans=m;
			}
			add(ans,-1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sum(i)-sum(i-1))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("0");
	return 0;
}