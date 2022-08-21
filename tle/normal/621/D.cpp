#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <limits>
#include <set>
#include <map>
using namespace std;
typedef double ld;
ld eps=1e-8,x,y,z;
ld ipld()
{
	double t;
	cin>>t;
	return t;
}
ld a[13];
ld ABS(ld x)
{
	if(x<0) return -x;
	return x;
}
#define L log2
string names[]={
"x^y^z","x^z^y","(x^y)^z","(x^z)^y",
"y^x^z","y^z^x","(y^x)^z","(y^z)^x",
"z^x^y","z^y^x","(z^x)^y","(z^y)^x"
};
void md()
{
	ld lx=L(x),ly=L(y),lz=L(z);
	ld llx=L(L(1/x)),lly=L(L(1/y)),llz=L(L(1/z));
	int id=0;
	a[++id]=llx+ly*z;
	a[++id]=llx+lz*y;
	a[++id]=llx+ly+lz;
	a[++id]=llx+ly+lz;
	a[++id]=lly+lx*z;
	a[++id]=lly+lz*x;
	a[++id]=lly+lx+lz;
	a[++id]=lly+lx+lz;
	a[++id]=llz+lx*y;
	a[++id]=llz+ly*x;
	a[++id]=llz+lx+ly;
	a[++id]=llz+lx+ly;
}
bool isone(ld s)
{
	if(fabs(s-1)<eps) return 1;
	return 0;
}
void sb()
{
	ld lx=L(x),ly=L(y),lz=L(z);
	ld llx=L(lx),lly=L(ly),llz=L(lz);
	int id=0;
	if(x>1)
	{
		a[++id]=llx+ly*z;
		a[++id]=llx+lz*y;
		a[++id]=llx+ly+lz;
		a[++id]=llx+ly+lz;
	}
	else
	{
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
	}
	if(y>1)
	{
		a[++id]=lly+lx*z;
		a[++id]=lly+lz*x;
		a[++id]=lly+lx+lz;
		a[++id]=lly+lx+lz;
	}
	else
	{
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
	}
	if(z>1)
	{
		a[++id]=llz+lx*y;
		a[++id]=llz+ly*x;
		a[++id]=llz+lx+ly;
		a[++id]=llz+lx+ly;
	}
	else
	{
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
		a[++id]=-233333333;
	}
}
void prt(char s)
{
	if(s=='x') printf("x^y^z\n");
	else if(s=='y') printf("y^x^z\n");
	else printf("z^x^y\n");
}
void prt(char a,char b)
{
	printf("%c^%c^%c\n",a,b,'x'+'y'+'z'-a-b);
}
int main()
{
	x=ipld();y=ipld();z=ipld();
	if(isone(x)&&isone(y)&&isone(z))
	{
		printf("x^y^z\n");
		return 0;
	}
	if(isone(x)+isone(y)+isone(z)==2)
	{
		char X='x',Y='y',Z='z';
		if(isone(x)&&isone(z)) swap(y,z), swap(Y,Z);
		if(isone(y)&&isone(z)) swap(x,z), swap(X,Z);
		//isone(x)&&isone(y)
		if(z>1) prt(Z);
		else prt(X);
		return 0;
	}
	if(isone(x)||isone(y)||isone(z))
	{
		char X='x',Y='y',Z='z';
		if(isone(y)) swap(x,y), swap(X,Y);
		if(isone(z)) swap(x,z), swap(X,Z);
		//isone(x)
		ld x2=L(y)*z,x3=L(z)*y;
		if(x2<=eps&&x3<=eps) prt(X);
		else if(x2>-eps&&x3>-eps)
		{
			if(fabs(x2-x3)<=eps) prt(min(Y,Z),max(Y,Z));
			else if(x2>=x3) prt(Y,Z);
			else prt(Z,Y);
		}
		else
		{
			if(x2>x3) prt(Y,X);
			else prt(Z,X);
		}
		return 0;
	}
	bool op=0;
	if(x<1&&y<1&&z<1) {md(); op=1;} else sb();
	if(!op)
	{
		ld maxn=-1000.0; int mid=0;
		for(int i=1;i<=12;i++)
		{
			ld cur=a[i];
			if(ABS(cur-maxn)<eps) continue; 
			if(cur<maxn) continue;
			maxn=cur; mid=i;
		}
		cout<<names[mid-1];
	}
	else
	{
		ld minn=1000000000.0; int mid=0;
		for(int i=1;i<=12;i++)
		{
			ld cur=a[i];
			if(ABS(cur-minn)<eps) continue; 
			if(cur>minn) continue;
			minn=cur; mid=i;
		}
		cout<<names[mid-1];
	}
}