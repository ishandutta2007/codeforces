#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,num,n[25],top,t;
bool flag[25];
bool check()
{
	for(int i=1;i<=num;i++)
	  if(!flag[i])return 0;
	return 1;
}
int main()
{
	scanf("%d",&x);
	while(x)
	{
		flag[++num]=x&1;
		x>>=1;
	}
	while(!check())
	{
		int p=num;
		while(flag[p])p--;
		t++,n[++top]=p;
		for(int i=1;i<=p;i++)flag[i]^=1;
		if(check())break;
		t++;
		p=1;
		while(flag[p])
		{
			flag[p]=0;
			p++;
		}
		flag[p]=1;
	}
	printf("%d\n",t);
	for(int i=1;i<=top;i++)printf("%d ",n[i]);
	printf("\n");
	return 0;
}