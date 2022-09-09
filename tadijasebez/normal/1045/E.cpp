#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
struct pt{ ll x,y;int id;pt(){}pt(ll a, ll b, int c=-1):x(a),y(b),id(c){}};
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
ll dot(pt a, pt b){ return a.x*b.x+a.y*b.y;}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
ll sq(pt a){ return dot(a,a);}
ll dist(pt a, pt b){ return sq(a-b);}
bool operator < (pt a, pt b){ return mp(a.x,a.y)<mp(b.x,b.y);}
vector<pt> ConvexHull(vector<pt> a)
{
	sort(a.begin(),a.end());
	vector<pt> b;
	for(int i=0;i<a.size();i++)
	{
		while(b.size()>1 && cross(a[i]-b.back(),b[b.size()-2]-b.back())<=0) b.pop_back();
		b.pb(a[i]);
	}
	int sz=b.size();
	for(int i=(int)a.size()-2;i>=0;i--)
	{
		while(b.size()>sz && cross(a[i]-b.back(),b[b.size()-2]-b.back())<=0) b.pop_back();
		b.pb(a[i]);
	}
	b.pop_back();
	return b;
}
const int N=1050;
int ty[N];
void rot(vector<pt> &a)
{
    int p=-1;
    for(int i=1;i<a.size();i++) if(ty[a[i].id]!=ty[a[0].id]){ p=i;break;}
    if(p==-1) return;
    vector<pt> b;
    for(int i=0;i<a.size();i++) b.pb(a[(i+p)%a.size()]);
    a=b;
}
vector<pair<int,int> > edges;
void AddEdge(int u, int v){ edges.pb(mp(u,v));}
ll Area(pt a, pt b, pt c){ return abs(cross(a,b)+cross(b,c)+cross(c,a));}
bool Inside(pt a, pt b, pt c, pt d)
{
	return Area(a,b,c)==Area(a,b,d)+Area(a,c,d)+Area(b,c,d);
}
void SolveTriangle(pt a, pt b, pt c, vector<pt> ps)
{
	int p=-1;
	for(int i=0;i<ps.size();i++) if(ty[ps[i].id]==ty[c.id]) p=i;
	if(p==-1)
	{
		for(int i=0;i<ps.size();i++) AddEdge(a.id,ps[i].id);
	}
	else
	{
		pt d=ps[p];
		AddEdge(d.id,c.id);
		vector<pt> nxt[3];
		for(int i=0;i<ps.size();i++) if(i!=p)
		{
			if(Inside(a,b,d,ps[i])) nxt[0].pb(ps[i]);
			else if(Inside(c,d,a,ps[i])) nxt[1].pb(ps[i]);
			else nxt[2].pb(ps[i]);
		}
		SolveTriangle(a,b,d,nxt[0]);
		SolveTriangle(c,d,a,nxt[1]);
		SolveTriangle(c,d,b,nxt[2]);
	}
}
bool Check(vector<pt> hull)
{
	int l=-1,r=hull.size();
	while(l+1<hull.size() && ty[hull[l+1].id]==ty[hull[0].id]) l++;
	while(r-1>=0 && ty[hull[r-1].id]==ty[hull.back().id]) r--;
	//printf("l:%i r:%i\n",l,r);
	if(r-l>1) return 0;
	return 1;
}
bool onHull[N];
void Triangulate(vector<pt> a)
{
	vector<pt> hull=ConvexHull(a);
	//for(int i=0;i<hull.size();i++) printf("(%lld %lld, %i) ",hull[i].x,hull[i].y,hull[i].id);printf("\n");
	rot(hull);
	if(!Check(hull)){ printf("Impossible\n");exit(0);}
	//for(int i=0;i<hull.size();i++) printf("(%lld %lld, %i %i) ",hull[i].x,hull[i].y,hull[i].id,ty[hull[i].id]);printf("\n");
	for(int i=0;i<hull.size();i++) onHull[hull[i].id]=1;
	if(ty[hull[0].id]==ty[hull.back().id])
	{
		for(int i=0;i+1<hull.size();i++) AddEdge(hull[i].id,hull[i+1].id);
		int p=-1;
		for(int i=0;i<a.size();i++) if(!onHull[a[i].id])
		{
			if(ty[a[i].id]!=ty[hull[0].id]){ p=i;break;}
		}
		if(p!=-1)
		{
			for(int i=0;i<hull.size();i++)
			{
				pt A=hull[i],B=hull[(i+1)%hull.size()],C=a[p];
				vector<pt> work;
				for(int j=0;j<a.size();j++) if(!onHull[a[j].id] && j!=p)
				{
					if(Inside(A,B,C,a[j])) work.pb(a[j]);
				}
				SolveTriangle(A,B,C,work);
			}
		}
		else
		{
			for(int i=0;i<a.size();i++) if(!onHull[a[i].id]) AddEdge(hull[0].id,a[i].id);
		}
	}
	else
	{
		int p=-1;
		for(int i=0;i<hull.size();i++) if(ty[hull[i].id]!=ty[hull[0].id]){ p=i;break;}
		if(p==-1){ printf("???\n");exit(0);}
		//printf("p:%i\n",p);
		for(int i=0;i+1<p;i++)
		{
			pt A=hull[i],B=hull[i+1],C=hull[p];
			AddEdge(A.id,B.id);
			vector<pt> work;
			for(int j=0;j<a.size();j++) if(!onHull[a[j].id])
			{
				if(Inside(A,B,C,a[j])) work.pb(a[j]);
			}
			//printf("A:(%lld %lld, %i)\n",A.x,A.y,A.id);
			//printf("B:(%lld %lld, %i)\n",B.x,B.y,B.id);
			//printf("C:(%lld %lld, %i)\n",C.x,C.y,C.id);
			//for(pt P:work) printf("(%lld %lld, %i) ",P.x,P.y,P.id);printf("\n");
			SolveTriangle(A,B,C,work);
		}
		for(int i=p;i+1<hull.size();i++)
		{
			pt A=hull[i],B=hull[i+1],C=hull[0];
			AddEdge(A.id,B.id);
			vector<pt> work;
			for(int j=0;j<a.size();j++) if(!onHull[a[j].id])
			{
				if(Inside(A,B,C,a[j])) work.pb(a[j]);
			}
			SolveTriangle(A,B,C,work);
		}
	}
}
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<pt> ps(n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%i %i %i",&x,&y,&ty[i]);
		ps[i]=pt(x,y,i);
	}
	if(n==1) return 0*printf("0\n");
	if(n==2)
	{
		if(ty[0]==ty[1]) printf("1\n0 1\n");
		else printf("0\n");
		return 0;
	}
	Triangulate(ps);
	printf("%i\n",edges.size());
	for(auto p:edges) printf("%i %i\n",p.first,p.second);
	return 0;
}