#include <bits/stdc++.h>
using namespace std;
struct pt{ int x,y;pt(int a=0, int b=0):x(a),y(b){}};
int Manhattan(pt a, pt b){ return abs(a.x-b.x)+abs(a.y-b.y);}
int Calc(pt a, pt b, pt c){ return Manhattan(a,b)+Manhattan(b,c)+Manhattan(a,c);}
void ckmn(int &a, int b){ a=min(a,b);}
void ckmx(int &a, int b){ a=max(a,b);}
int main()
{
	int n,i,ans=0;
	scanf("%i",&n);
	vector<pt> ps,ex;
	ps.resize(n);
	for(i=0;i<n;i++) scanf("%i %i",&ps[i].x,&ps[i].y);
	int lx=ps[0].x,ly=ps[0].y,rx=ps[0].x,ry=ps[0].y;
	for(pt p:ps) ckmn(lx,p.x),ckmn(ly,p.y),ckmx(rx,p.x),ckmx(ry,p.y);
	for(pt p:ps) if(p.x==lx || p.x==rx || p.y==ly || p.y==ry) ex.push_back(p);
	for(pt a:ps) for(pt b:ex) for(pt c:ex) ckmx(ans,Calc(a,b,c));
	printf("%i ",ans);
	for(i=4;i<=n;i++) printf("%i ",2*(rx+ry-lx-ly));
	return 0;
}