#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int root,tsz,val[N],mx[N],sz[N],y[N],ls[N],rs[N];
int MakeNode(int x)
{
	tsz++;
	y[tsz]=(rand()<<12)+rand();
	val[tsz]=mx[tsz]=x;
	sz[tsz]=1;
}
void pull(int c){ if(c) mx[c]=max(val[c],max(mx[ls[c]],mx[rs[c]])),sz[c]=sz[ls[c]]+sz[rs[c]]+1;}
void RotL(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;ls[a]=c;
	pull(c);pull(a);
	c=a;
}
void RotR(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;rs[a]=c;
	pull(c);pull(a);
	c=a;
}
void Insert(int &c, int a, int k)
{
	if(!c){ c=MakeNode(a);return;}
	if(sz[ls[c]]>=k || max(mx[ls[c]],val[c])>a)
	{
		Insert(ls[c],a,k);
		if(y[ls[c]]>y[c]) RotR(c);
		else pull(c);
	}
	else
	{
		Insert(rs[c],a,k-sz[ls[c]]-1);
		if(y[rs[c]]>y[c]) RotL(c);
		else pull(c);
	}
}
void P(int c){ if(!c) return;P(rs[c]);printf("%i ",c);P(ls[c]);}
int main()
{
	srand(time(0));
    int n,i,a,c;
    scanf("%i",&n);
    for(i=1;i<=n;i++)
	{
		scanf("%i %i",&a,&c);
		Insert(root,a,c);
	}
	P(root);
	return 0;
}