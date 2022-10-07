#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double EPS=1e-9;
const double Pi=acos(-1.0);
struct Point
{
	double x,y;
	int id;
	Point(double xx=0,double yy=0){x=xx,y=yy;}
	inline Point operator+(Point p){return Point(x+p.x,y+p.y);}
	inline Point operator-(Point p){return Point(x-p.x,y-p.y);}
	inline Point operator*(double d){return Point(x*d,y*d);}
	inline Point operator/(double d){return Point(x/d,y/d);}
	inline double dot(Point p){return x*p.x+y*p.y;}
	inline double det(Point p){return x*p.y-y*p.x;}
	inline double abs2(){return x*x+y*y;}
	inline double abs(){return sqrt(abs2());}
	inline Point unit(){return *this/abs();}
	inline Point rot90(){return Point(-y,x);}
	inline int quad()
	{
		if(x<0&&y<=0)return 1;
		if(x>=0&&y<0)return 2;
		if(x>0&&y>=0)return 3;
		return 4;
	}
}a[50005],b[50005],p[100005];
struct Node
{
	int l,r;
}line[50005];
int n,m,tot,num,c[100005],last[100005],pre[100005],nxt[100005];
inline double dis2(Point p1,Point p2)
{
	return p1.det(p2)*p1.det(p2)/(p2-p1).abs2();
}
inline pair<Point,Point>isCL(Point p1,Point p2,double r)
{
	double d=dis2(p1,p2);
	Point m=(p2-p1).unit().rot90()*sqrt(d);
	if(p1.det(p2)>0)m=m*(-1.0);
	d=sqrt(max(0.0,r*r-d));
	Point dir=(p2-p1).unit()*d;
	return make_pair(m+dir,m-dir);
}
inline Point isLL(Point p1,Point p2,Point q1,Point q2)
{
	double a=(q1-p1).det(p2-p1);
	double b=(p2-p1).det(q2-p1);
	return q1+(q2-q1)*a/(a+b);
}
void add(int p)
{
	while(p<=tot)
	{
		c[p]++;
		p+=p^(p&(p-1));
	}
}
int ask(int p)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
int ask(int l,int r)
{
	return ask(r)-ask(l-1);
}
inline bool cmp(Point a,Point b)
{
	return a.quad()==b.quad()?a.det(b)>=0:a.quad()<b.quad();
}
inline bool cmp2(Node a,Node b)
{
	return a.r-a.l<b.r-b.l;
}
void Pre(double r)
{
//	printf("%lf:\n",r);
	tot=0;
	for(int i=1;i<=n;i++)
	{
		if(dis2(a[i],b[i])>r*r+EPS)continue;
		pair<Point,Point>res=isCL(a[i],b[i],r);
		p[++tot]=res.first;
		p[++tot]=res.second;
		p[tot-1].id=p[tot].id=i;
//		printf("(%lf,%lf) (%lf,%lf)\n",p[tot-1].x,p[tot-1].y,p[tot].x,p[tot].y);
	}
	sort(p+1,p+tot+1,cmp);
	for(int i=1;i<=tot;i++)last[p[i].id]=i;
}
bool check(double r)
{
	memset(c,0,sizeof(c));
	Pre(r);
	long long sum=0;
	for(int i=1;i<=tot;i++)
	{
		if(last[p[i].id]==i)continue;
		sum+=ask(i+1,last[p[i].id]-1);
		add(last[p[i].id]);
	}
	return sum>m;
}
int main()
{
	scanf("%d",&n);
	double x,y;
	scanf("%lf%lf%d",&x,&y,&m);
	x/=1000,y/=1000;
	for(int i=1;i<=n;i++)
	{
		double aa,bb;
		scanf("%lf%lf",&aa,&bb);
		aa/=1000,bb/=1000;
		a[i]=Point(0,bb),b[i]=Point(1,aa+bb);
		a[i]=a[i]-Point(x,y);
		b[i]=b[i]-Point(x,y);
//		printf("(%lf,%lf)->(%lf,%lf)\n",a[i].x,a[i].y,b[i].x,b[i].y);
	}
	double l=1e-18,r=1e18;
	for(int i=1;i<=30;i++)
	{
		double mid=sqrt(l*r);
		if(check(mid))r=mid;
		else l=mid;
	}
	r=l;
	Pre(r);
	for(int i=1;i<=tot;i++)
	{
		if(last[p[i].id]==i)continue;
		line[++num].l=i,line[num].r=last[p[i].id];
	}
	sort(line+1,line+num+1,cmp2);
	int sum=0;
	double ans=0;
	for(int i=1;i<=tot;i++)pre[i]=i-1,nxt[i]=i+1;
	for(int i=1;i<=num;i++)
	{
		int x=line[i].l,pos=p[line[i].l].id;
		x=nxt[x];
		while(x!=line[i].r)
		{
			ans+=isLL(a[pos],b[pos],a[p[x].id],b[p[x].id]).abs();
			sum++;
			x=nxt[x];
		}
		x=line[i].l;
		pre[nxt[x]]=pre[x];
		nxt[pre[x]]=nxt[x];
		x=line[i].r;
		pre[nxt[x]]=pre[x];
		nxt[pre[x]]=nxt[x];
	}
	ans+=r*(m-sum);
	printf("%.12lf\n",ans);
	return 0;
}