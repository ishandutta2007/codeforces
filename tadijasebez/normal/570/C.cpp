#include <stdio.h>
#include <cstring>
const int N=300050;
const int M=N*4;
int x[M],rs[M],ls[M],clock,root;
int max(int a, int b){ return a>b?a:b;}
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se)
	{
		x[c]=max(x[c],val);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
int A;
void Get(int c, int ss, int se, int qi)
{
	A=max(A,x[c]);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
char word[N],tmp[N];
int sol,n;
int l[M],r[M],time;
void Change(int x, char h)
{
	if(word[x]=='.' && h!='.')
	{
		A=0;
		Get(root,1,n,x);
		sol-=r[A]-l[A];
		if(l[A]!=x)
		{
			time++;
			l[time]=l[A];
			r[time]=x-1;
			sol+=r[time]-l[time];
			Set(root,1,n,l[time],r[time],time);
		}
		if(r[A]!=x)
		{
			time++;
			l[time]=x+1;
			r[time]=r[A];
			sol+=r[time]-l[time];
			Set(root,1,n,l[time],r[time],time);
		}
	}
	else if(word[x]!='.' && h=='.')
	{
		int b=x,e=x;
		if(word[x-1]=='.')
		{
			A=0;
			Get(root,1,n,x-1);
			sol-=r[A]-l[A];
			b=l[A];
		}
		if(word[x+1]=='.')
		{
			A=0;
			Get(root,1,n,x+1);
			sol-=r[A]-l[A];
			e=r[A];
		}
		time++;
		l[time]=b;
		r[time]=e;
		sol+=r[time]-l[time];
		Set(root,1,n,l[time],r[time],time);
	}
	word[x]=h;
}
int main()
{
	int m,x,i;
	char h;
	scanf("%i %i",&n,&m);
	scanf("%s",tmp+1);
	for(i=1;i<=n;i++) Change(i,tmp[i]);
	while(m --> 0)
	{
		scanf("%i %c",&x,&h);
		Change(x,h);
		printf("%i\n",sol);
	}
	return 0;
}