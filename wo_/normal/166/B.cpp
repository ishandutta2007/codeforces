#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Point{
	long long x,y;
	bool which;
	Point(){}
	Point(int x,int y,bool flg):x(x),y(y),which(flg){}
	Point operator-(const Point &p);
	long long det(Point p);
};

Point Point::operator-(const Point &p)
{
	return Point(x-p.x,y-p.y,false);
}

long long Point::det(Point p)
{
	return x*p.y-y*p.x;
}

bool cmp(const Point &p1,const Point &p2)
{
	if(p1.x!=p2.x) return p1.x<p2.x;
	return p1.y<p2.y;
}

vector<Point> convex_hull(vector<Point> ps)
{
	int N=ps.size();
	sort(ps.begin(),ps.end(),cmp);
	vector<Point> res(N*2);
	int k=0;
	for(int i=0;i<N;i++)
	{
		while(k>1&&(res[k-1]-res[k-2]).det(ps[i]-res[k-1])<0) k--;
		res[k]=ps[i];
		k++;
	}
	for(int i=N-2,t=k;i>=0;i--)
	{
		while(k>t&&(res[k-1]-res[k-2]).det(ps[i]-res[k-1])<0) k--;
		res[k]=ps[i];
		k++;
	}
	res.resize(k-1);
	return res;
}

vector<Point> ps;

int main()
{
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ps.push_back(Point(x,y,true));
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ps.push_back(Point(x,y,false));
	}
	vector<Point> hull=convex_hull(ps);
	bool flg=true;
	for(int i=0;i<hull.size();i++)
	{
		if(hull[i].which==false) flg=false;
	}
	if(flg) printf("YES\n");
	else printf("NO\n");
	return 0;
}