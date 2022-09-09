#include <bits/stdc++.h>
using namespace std;
int sgn(int x){ return x?x/abs(x):x;}
struct pt{ int x,y;pt(int a=0, int b=0):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
int cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
int orient(pt a, pt b, pt c){ return sgn(cross(a-b,c-b));}
struct line{ pt p;int c;line(){}line(pt a, pt b):p(a-b),c(cross(p,a)){}};
int side(line a, pt b){ return cross(a.p,b)-a.c;}
int sgside(line a, pt b){ return sgn(side(a,b));}
struct seg{ line l;pt a,b;seg(){}seg(pt _a, pt _b):l(_a,_b),a(_a),b(_b){}};
int side(seg a, pt b){ return side(a.l,b);}
int sgside(seg a, pt b){ return sgn(side(a,b));}
bool sec(seg a, seg b){ return orient(a.a,a.b,b.a)!=orient(a.a,a.b,b.b) && orient(b.a,b.b,a.a)!=orient(b.a,b.b,a.b);}
int main()
{
	int i,j;
	pt a[4],b[4];
	seg sa[4],sb[4];
	for(i=0;i<4;i++) scanf("%i %i",&a[i].x,&a[i].y);
	for(i=0;i<4;i++) scanf("%i %i",&b[i].x,&b[i].y);
	for(i=0;i<4;i++) sa[i]=seg(a[i],a[(i+1)%4]);
	for(i=0;i<4;i++) sb[i]=seg(b[i],b[(i+1)%4]);
	for(i=0;i<4;i++) for(j=0;j<4;j++) if(sec(sa[i],sb[j])) return 0*printf("YES\n");
	for(i=0;i<4;i++) if(sgside(sb[0],a[i])!=-sgside(sb[2],a[i]) && sgside(sb[1],a[i])!=-sgside(sb[3],a[i])) return 0*printf("YES\n");
	for(i=0;i<4;i++) if(sgside(sa[0],b[i])!=-sgside(sa[2],b[i]) && sgside(sa[1],b[i])!=-sgside(sa[3],b[i])) return 0*printf("YES\n");
	printf("NO\n");
	return 0;
}