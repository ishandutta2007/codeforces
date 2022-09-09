#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct pt{ ll x,y;pt(){}pt(int a, int b):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a){ return pt(a.x,-a.y);}
bool operator < (pt a, pt b){ return a.x<b.x || (a.x==b.x && a.y<b.y);}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
set<pt> hull[2];
bool Check(int id, pt f)
{
	auto it=hull[id].lower_bound(f);
	if(it==hull[id].end()) return 0;
	if(it==hull[id].begin()) return it->x==f.x;
	pt r=*it;it--;
	pt l=*it;
	return cross(r-f,l-f)>=0;
}
bool Inside(pt f){ return Check(0,f) && Check(1,-f);}
bool bad(set<pt>::iterator it, int id)
{
	if(it==hull[id].begin() || it==hull[id].end()) return 0;
	pt a,b=*it,c;it--;a=*it;it++;it++;
	if(it==hull[id].end()) return 0;
	c=*it;
	if(cross(c-b,a-b)>=0) return 1;
	return 0;
}
void Add(int id, pt f)
{
	auto it=hull[id].lower_bound(f);
	if(it==hull[id].end()) hull[id].insert(f);
	else if(it==hull[id].begin())
	{
		if(it->x==f.x) return;
		hull[id].insert(f);
	}
	else
	{
		pt r=*it;it--;
		pt l=*it;
		if(cross(r-f,l-f)>=0) return;
		hull[id].insert(f);
	}
	it=hull[id].find(f);it++;
	while(bad(it,id))
	{
		pt e=*it;it++;
		hull[id].erase(e);
	}
	it=hull[id].find(f);if(it!=hull[id].begin()) it--;
	while(bad(it,id))
	{
		pt e=*it;it--;
		hull[id].erase(e);
	}
}
int main()
{
	int q,x,y,t;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&x,&y);
		pt o=pt(x,y);
		if(t==1) Add(0,o),Add(1,-o);
		else printf("%s\n",Inside(o)?"YES":"NO");
	}
	return 0;
}