#include <bits/stdc++.h>
using namespace std;
struct pt{ int x,y;pt(){}pt(int a, int b):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
int cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
struct line
{
	pt p;int c;
	line(){}
	line(pt a, pt b){ p=a-b;c=cross(p,a);}
};
int side(line a, pt b){ return a.c-cross(a.p,b);}
int sgn(int x){ return x?x/abs(x):x;}
int main()
{
	int n,d,i,m,x,y;
	line A,B,C,D;
	scanf("%i %i",&n,&d);
	A=line(pt(0,d),pt(n-d,n));
	B=line(pt(d,0),pt(n,n-d));
	C=line(pt(d,0),pt(0,d));
	D=line(pt(n,n-d),pt(n-d,n));
	scanf("%i",&m);
	while(m--)
	{
		scanf("%i %i",&x,&y);
		pt p=pt(x,y);
		if(sgn(side(A,p))!=sgn(side(B,p)) && sgn(side(C,p))!=sgn(side(D,p))) printf("YES\n");
		else printf("NO\n");
		//printf("sa:%i sb:%i sc:%i sd:%i\n",side(A,p),side(B,p),side(C,p),side(D,p));
	}
	return 0;
}