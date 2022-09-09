#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
struct pt{ ll x,y;int deg,id;pt(){}pt(ll a, ll b):x(a),y(b){}};
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
bool operator < (pt a, pt b){ return mp(a.x,a.y)<mp(b.x,b.y);}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
pt pivot;
int Part(pt a)
{
	a=a-pivot;
	if(a.y>0 || (a.y==0 && a.x>0)) return 0;
	return 1;
}
bool comp(pt a, pt b){ return mp(Part(a),(ll)0)<mp(Part(b),cross(a-pivot,b-pivot));}
vector<pair<int,int>> edges;
void AddEdge(int u, int v){ edges.pb(mp(u,v));}
void Solve(vector<pt> a)
{
	if(a.size()<=1) return;
	int mx=0;
	for(int i=1;i<a.size();i++) if(a[mx].deg<a[i].deg) mx=i;
	//for(int i=0;i<a.size();i++) printf("(%lld %lld, id:%i deg:%i) ",a[i].x,a[i].y,a[i].id,a[i].deg);printf("\n");
	if(a[mx].deg==1)
	{
		int z=-1;
		for(int i=0;i<a.size();i++) if(a[i].deg==0) z=i;
		if(z==-1){ printf("z==-1???\n");exit(0);}
		for(int i=0;i<a.size();i++) if(i!=z) AddEdge(a[i].id,a[z].id);
	}
	else
	{
		swap(a[0],a[mx]);
		pivot=a[0];
		sort(a.begin()+1,a.end(),comp);
		//for(int i=0;i<a.size();i++) printf("(%lld %lld, id:%i deg:%i) ",a[i].x,a[i].y,a[i].id,a[i].deg);printf("\n");
		function<int(int)> nxt=[&](int i){ return i+1==a.size()?1:i+1;};
		int l=-1,r=-1;
		int sum=a[1].deg-1;
		int j=1;
		for(int i=1;i<a.size();i++)
		{
			while(nxt(j)!=i && cross(a[i]-a[0],a[nxt(j)]-a[0])>0)
			{
				j=nxt(j);
				sum+=a[j].deg-1;
			}
			if(sum<0 && a[0].deg+sum>=1){ l=i;r=j;break;}
			sum-=a[i].deg-1;
			if(j==i) sum+=a[nxt(j)].deg-1,j=nxt(j);
		}
		if(l==-1){ printf("l==-1???\n");exit(0);}
		vector<pt> ls,rs;
		for(int i=l;i!=nxt(r);i=nxt(i)) ls.pb(a[i]);
		for(int i=nxt(r);i!=l;i=nxt(i)) rs.pb(a[i]);
		pt tmp=a[0];
		tmp.deg=-sum;
		ls.pb(tmp);
		tmp.deg=a[0].deg+sum;
		rs.pb(tmp);
		Solve(ls);
		Solve(rs);
	}
}
void run()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int a,b;
		scanf("%i %i",&a,&b);
		vector<int> deg(b);
		for(int &i:deg) scanf("%i",&i);
		vector<pt> ps(a+b);
		for(int i=1;i<=a+b;i++)
		{
			scanf("%lld %lld",&ps[i-1].x,&ps[i-1].y);
			if(i>a)
			{
				ps[i-1].id=i-a;
				ps[i-1].deg=deg[i-a-1];
			}
			else
			{
				ps[i-1].id=i;
				ps[i-1].deg=0;
			}
		}
		edges.clear();
		Solve(ps);
		printf("YES\n");
		for(auto p:edges) printf("%i %i\n",p.first,p.second);
	}
}
bool Check(vector<pt> a)
{
	for(int i=0;i<a.size();i++)
		for(int j=i+1;j<a.size();j++)
			if(a[i].x==a[j].x && a[i].y==a[j].y) return 0;
	for(int i=0;i<a.size();i++)
		for(int j=i+1;j<a.size();j++)
			for(int k=j+1;k<a.size();k++)
				if(cross(a[i]-a[j],a[k]-a[j])==0) return 0;
	return 1;
}
vector<pt> Make(int n)
{
	vector<pt> ret;
	do
	{
		ret.clear();
		for(int i=0;i<n;i++) ret.pb(pt(rand()%11-5,rand()%11-5));
	}while(!Check(ret));
	return ret;
}
bool CheckSolution(vector<pt> ps, int a, int b)
{
	for(int i=0;i<edges.size();i++)
	{
		for(int j=i+1;j<edges.size();j++)
		{
			pt A=ps[edges[i].first+a-1];
			pt B=ps[edges[i].second-1];
			pt C=ps[edges[j].first+a-1];
			pt D=ps[edges[j].second-1];
			if(cross(A-C,B-C)*cross(A-D,B-D)<0 && cross(C-A,D-A)*cross(C-B,D-B)<0) return 0;
		}
	}
	return 1;
}
void test()
{
	srand(time(0));
	int t=100000;
	while(t--)
	{
		int a,b;
		a=rand()%5+1;b=rand()%5+1;
		vector<pt> ps=Make(a+b);
		int can=a-1;
		for(int i=0;i<a;i++) ps[i].id=i+1,ps[i].deg=0;
		for(int i=a;i<a+b;i++)
		{
			ps[i].id=i-a+1;
			ps[i].deg=1+(i==a+b-1?can:rand()%(can+1));
			can-=ps[i].deg-1;
		}
		edges.clear();
		Solve(ps);
		if(edges.size()!=a+b-1 || !CheckSolution(ps,a,b))
		{
			printf("%i %i\n",a,b);
			for(pt p:ps) printf("%lld %lld deg:%i id:%i\n",p.x,p.y,p.deg,p.id);
			for(auto p:edges) printf("%i %i\n",p.first,p.second);
			return;
		}
	}
	printf("OK\n");
}
int main()
{
	//test();
	run();
	return 0;
}