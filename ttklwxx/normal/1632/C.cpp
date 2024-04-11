#include<iostream>
#include<cstdio>
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
char s[100005];
int main()
{
	int t,a,b,ans,mb;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		//printf("%d\n",a|b);
		ans=b-a;
		for(int i=a;i<=b;i++)
		{
			mb=i;
			for(int j=20;j>=0;j--)
			{
				if(i&(1<<j))
				{
					if(b<=mb)break;
					continue;
				}
				if((b&(1<<j)))
				{
					mb+=(1<<j);
					if(mb>=b)break;
					continue;
				}
			}
			//if(i==8)printf("%d\n",mb); 
			//if(i=printf("???\n")=32)printf("%d %d\n",mb,i);
			ans=min(ans,mb-b+i-a+1);
			//if(mb-b+i-a+1==15803)printf("%d %d\n",mb,i);
		}
		printf("%d\n",ans);
	}
	return 0;
}