#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FILL(a,b) memset(a,b,sizeof(a))
#define X first
#define Y second
#define mp make_pair
#define ii pair<int,int>
#define inf 0x3f3f3f3f
#define MAXN 100020
#define dd pair<double,double>
struct BLOCK
{
int y,l,r,w;
BLOCK(int _y,int _l,int _r,int _bel):y(_y),l(_l),r(_r),w(_bel){}
BLOCK(){}
}block[MAXN];
int n,hl,hr,zz[MAXN],ap[120],v[MAXN];
int main()
{
cin>>hl>>hr>>n;
int tot=0;
FOR(i,1,n)
{
	int p,l,r,y;
	char f;
	scanf("%d %c%d%d",&p,&f,&l,&r);
	zz[i]=p;
	if(f=='T')
		y=100;
	else
		y=0;
	v[i]=y==100;
	FOR(j,-n,n)
		block[++tot]=BLOCK(y+200*j,l,r,i);
}
dd sPt=mp(0,hl);
int answer=0;
FOR(j,-2*n,2*n)
{
	dd nPt=mp(100000,((abs(j)&1)?(100-hr):(hr))+100*j);
	double k;
	if(nPt.Y!=hl)
		k= 100000./(nPt.Y-sPt.Y);
	else
		continue;
	FILL(ap,0);
	int nowanswer=0;
	ii cnt=mp(0,0);
	FOR(i,1,tot)
	{
		double temp=((double)block[i].y-hl)*k;
		if(temp>=block[i].l&&temp<=block[i].r)
		{
			++ap[block[i].w]; 
			if(ap[block[i].w]>1)
			{
				nowanswer=-inf;
				break; 
			}
			nowanswer+=zz[block[i].w];
			if(v[block[i].w])
				++cnt.X;
			else
				++cnt.Y;
		}
	}
	if(cnt.X+cnt.Y==abs(j))
		answer=max(answer,nowanswer);
}
cout<<answer<<endl;
return 0;
}