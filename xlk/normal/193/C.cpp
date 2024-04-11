#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int f[6][6];
int x,y,z,xyz;
int x0,x1,y0,y1,z0,z1;
string a,b,c,d;
void fail()
{
	puts("-1");
	exit(0);	
}
int main()
{
	for(int i=1;i<=4;i++)
		for(int j=i+1;j<=4;j++)
			scanf("%d",f[i]+j),f[j][i]=f[i][j];
	xyz=f[1][2]+f[1][3]+f[2][3];
	if(xyz&1)
		fail();
	xyz>>=1;
	x=xyz-f[1][2];
	y=xyz-f[1][3];
	z=xyz-f[2][3];
	if((f[4][1]+f[4][2]-y-z)&1)
		fail();
	if((f[4][1]+f[4][3]-x-z)&1)
		fail();
	if((f[4][2]+f[4][3]-x-y)&1)
		fail();
	x1=(f[4][1]+f[4][2]-y-z)/2;
	y1=(f[4][1]+f[4][3]-x-z)/2;
	z0=(f[4][2]+f[4][3]-x-y)/2;
	x0=x-x1;
	y0=y-y1;
	z1=z-z0;
	int w=0;
	while((x0<0||y0<0||z1<0))
	{
		w++;
		x1--,y1--,z0--;
		x0++,y0++,z1++;
	}
	if((x1<0||y1<0||z0<0)||(x0<0||y0<0||z1<0))
		fail();
	fr(i,w)
	{
		a+="a";
		b+="a";
		c+="a";
		d+="b";
	}
	fr(i,x0)
	{
		a+="a";
		b+="a";
		c+="b";
		d+="a";
	}
	fr(i,x1)
	{
		a+="a";
		b+="a";
		c+="b";
		d+="b";
	}
	fr(i,y0)
	{
		a+="a";
		b+="b";
		c+="a";
		d+="a";
	}
	fr(i,y1)
	{
		a+="a";
		b+="b";
		c+="a";
		d+="b";
	}
	fr(i,z0)
	{
		a+="a";
		b+="b";
		c+="b";
		d+="a";
	}
	fr(i,z1)
	{
		a+="a";
		b+="b";
		c+="b";
		d+="b";
	}
	cout << a.size() << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}