#include<stdio.h>
int n,m;
int p[100020],pp;
int v[100020];
int c[100020];
int a[100020],aa;
int l[100020];
int on[100020];
int ins(int xx)
{
	int x=xx;
	if(on[x])
		return 0;
	aa=0;
	int i;
	for(i=0;p[i]*p[i]<=x;i++)
	{
		if(x%p[i]==0)
		{
			while(x%p[i]==0)
				x/=p[i];
			a[aa++]=p[i];
		}	
	}
	if(x>1)
		a[aa++]=x;
	for(i=0;i<aa;i++)
	{
		if(c[a[i]])
			return l[a[i]];
	}
	on[xx]=1;
	for(i=0;i<aa;i++)
	{
		c[a[i]]=1;
		l[a[i]]=xx;
	}
	return -1;
}
int era(int x)
{
	if(!on[x])
		return 0;
	on[x]=0;
	aa=0;
	int i;
	for(i=0;p[i]*p[i]<=x;i++)
	{
		if(x%p[i]==0)
		{
			while(x%p[i]==0)
				x/=p[i];
			a[aa++]=p[i];
		}	
	}
	if(x>1)
		a[aa++]=x;
	for(i=0;i<aa;i++)
	{
		c[a[i]]=0;
		l[a[i]]=0;
	}
	return -1;
}
void P()
{
	int i,j;
	for(i=2;i<=100000;i++)
	{
		if(!v[i])
			p[pp++]=i;
		for(j=0;j<pp&&i*p[j]<=100000;j++)
		{
			v[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	P();
	int i;
	for(i=0;i<m;i++)
	{
		char o[5];
		int x;
		scanf("%s %d",o,&x);
		if(*o=='+')
		{
			int res=ins(x);
			if(res==0)
				puts("Already on");
			else if(res==-1)
				puts("Success");
			else
				printf("Conflict with %d\n",res);
		}
		else
		{
			int res=era(x);
			if(res==0)
				puts("Already off");
			if(res==-1)
				puts("Success");
		}
	}
	return 0;
}