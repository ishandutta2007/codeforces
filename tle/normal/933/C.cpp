#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
//https://gsamaras.wordpress.com/code/determine-where-two-circles-intersect-c/
 
/*
 * Find the intersection point(s) of two circles,
 * when their centers and radiuses are given (2D).
 */
 
class Point2d{
public:
    Point2d() {}
    Point2d(double x, double y)
        : X(x), Y(y) {}
     
    double x() const { return X; }
    double y() const { return Y; }
     
    /**
     * Returns the norm of this vector.
     * @return the norm
    */
    double norm() const {
        return sqrt( X * X + Y * Y );
    }
     
    void setCoords(double x, double y) {
        X = x; Y = y;
    }
     
    // Print point
    friend std::ostream& operator << ( std::ostream& s, const Point2d& p )  {
      s << p.x() << " " << p.y();
      return s;
    }
private:
    double X;
    double Y;
};
const ld eps=1e-7;
class Circle{
public:
    /**
     * @param R - radius
     * @param C - center
     */
    Circle(double R, Point2d& C) 
        : r(R), c(C) {}
         
    /**
     * @param R - radius
     * @param X - center's x coordinate
     * @param Y - center's y coordinate
     */
    Circle(double R, double X, double Y) 
        : r(R), c(X, Y) {}    
     Circle() {	 }
    Point2d getC() const { return c; }
    double getR() const { return r; }
     
    vector<Point2d> intersect(const Circle& C2,int&rt) {
        // distance between the centers
        double d = Point2d(c.x() - C2.c.x(), 
                c.y() - C2.c.y()).norm();
        rt=0;
        // find number of solutions
        if(d > r + C2.r+eps) // circles are too far apart, no solution(s)
            return vector<Point2d>();
        else if(fabs(d) <eps&& fabs(r-C2.r)<eps) // circles coincide
            return vector<Point2d>();
        // one circle contains the other
        else if(d + min(r, C2.r)+eps < max(r, C2.r))
            {rt=-1; return vector<Point2d>();}
        else
        {
            double a = (r*r - C2.r*C2.r + d*d)/ (2.0*d);
            double h = sqrt(r*r - a*a);
             
            // find p2
            Point2d p2( c.x() + (a * (C2.c.x() - c.x())) / d,
                    c.y() + (a * (C2.c.y() - c.y())) / d);
             
            // find intersection points p3
            Point2d i1,i2;
			i1.setCoords( p2.x() + (h * (C2.c.y() - c.y())/ d),
                    p2.y() - (h * (C2.c.x() - c.x())/ d)
            );
            i2.setCoords( p2.x() - (h * (C2.c.y() - c.y())/ d),
                    p2.y() + (h * (C2.c.x() - c.x())/ d)
            );
            vector<Point2d> op; op.push_back(i1);
            if(fabs(i1.x()-i2.x())<eps&&fabs(i1.y()-i2.y())<eps) return op;
            op.push_back(i2); return op;
        }
    }
     
    // Print circle
    friend std::ostream& operator << ( std::ostream& s, const Circle& C )  {
      s << "Center: " << C.getC() << ", r = " << C.getR();
      return s;
    }
private:
    // radius
    double r;
    // center
    Point2d c;
     
};
bool operator < (Point2d a,Point2d b)
{
	if(fabs(a.x()-b.x())>eps) return a.x()<b.x();
	return a.y()<b.y();
}
int n,x[2333],y[2333],r[23333];
Circle c[2333]; bool fu[2333];
int ff[23333];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{
	a=gf(a),b=gf(b);
	if(a!=b) ff[a]=b;
}
int cc(vector<Point2d> op)
{
		sort(op.begin(),op.end());
		int cnt=0;
		for(int i=0;i<op.size();++i)
		{
			if(i+1<op.size()&&
			fabs(op[i].x()-op[i+1].x())<eps
			&&fabs(op[i].y()-op[i+1].y())<eps) continue;
			++cnt;
		}
		return cnt;
}
int main()
{
	cin>>n; int g=0,h=0;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i]>>r[i],c[i]=Circle(r[i],x[i],y[i]);
	int ans=1;
	vector<Point2d> tot;
	for(int i=1;i<=n;++i)
	{
		vector<Point2d> op;
		for(int j=1;j<=n;++j) if(i!=j)
		{
			int aa=0;
			vector<Point2d> sb=
			c[i].intersect(c[j],aa);
			if(sb.size()) uni(i,j);
			for(auto g:sb) op.push_back(g),tot.push_back(g);
		}
		ans+=cc(op);
	}
	ans-=cc(tot);
	for(int i=1;i<=n;++i) ans+=gf(i)==i;
	printf("%d\n",ans);
}