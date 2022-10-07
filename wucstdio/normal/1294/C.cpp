#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[33],top;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		for(int i=2;i*i<=n;i++)
		{
			while(n%i==0)
			{
				p[++top]=i;
				n/=i;
			}
		}
		if(n!=1)p[++top]=n;
		int a=1,b=1,c=1;
		for(int i=1;i<=top;i++)
		{
			if(a==1)a*=p[i];
			else if(b==1||b==a)b*=p[i];
			else c*=p[i];
		}
		if(a==1||b==1||c==1||a==b||b==c||a==c)printf("NO\n");
		else printf("YES\n%d %d %d\n",a,b,c);
	}
	return 0;
}