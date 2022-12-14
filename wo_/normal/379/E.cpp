#include<cstdio>
#include<complex>
#include<cmath>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;

const double PI=acos(-1.0);

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<Point> Polygon;

const double eps=1e-9;

template<class T> bool eq(T a,T b){
	return abs(a-b)<eps;
}

template<class T> int sgn(T r){
	return eq(r,0.0)?0:(r>0?1:-1);
}

double crP(Vector v1,Vector v2){
	return (conj(v1)*v2).imag();
}

double crP(Point p1,Point p2,Point p3){
	return crP(p2-p1,p3-p1);
}


struct Line{
	double a,b,c;//ax+by=c
	Line(){}
	Line(double a,double b,double c):a(a),b(b),c(c){}
	Line(Point p1,Point p2){//not verified
		if(eq(abs(p1-p2),0.0)){
			fprintf(stderr,"called Line for same points\n");
			assert(0);
		}
		double x1=p1.real(),y1=p1.imag();
		double x2=p2.real(),y2=p2.imag();
		a=y2-y1;
		b=-(x2-x1);
		c=x1*y2-x2*y1;
	}
};

double det(double a,double b,double c,double d){
	return a*d-b*c;
}

Point linesIntersection(Line l1,Line l2){/*sNAN*/
	double a=l1.a,b=l1.b,c=l1.c;
	double d=l2.a,e=l2.b,f=l2.c;
	double den=det(a,b,d,e);
	double numx=det(c,b,f,e);
	double numy=det(a,c,d,f);
	if(eq(den,0.0)){
		return Point(NAN,NAN);
	}
	return Point(numx/den,numy/den);
}

Point linesIntersection(Point p1,Point p2,Point p3,Point p4){
	Line l1=Line(p1,p2);
	Line l2=Line(p3,p4);
	return linesIntersection(l1,l2);
}

Polygon convexCut(Polygon p,Point a,Point b){
	Polygon q;
	if(p.size()==0) return q;
	p.push_back(p[0]);
	for(int i=0;i<p.size()-1;i++){
		if(sgn(crP(a,b,p[i]))>=0) q.push_back(p[i]);
		if(sgn(crP(a,b,p[i]))*sgn(crP(a,b,p[i+1]))<0) q.push_back(linesIntersection(a,b,p[i],p[i+1]));
	}
	return q;
}

Polygon convexCut(Polygon p1,Polygon p2){
	p2.push_back(p2[0]);
	Polygon res=p1;
	for(int i=0;i<p2.size()-1;i++){
		if(eq(p2[i],p2[i+1])) continue;
		res=convexCut(res,p2[i],p2[i+1]);
	}
	return res;
}

double getArea(Polygon p){
	if(p.size()<=2) return 0;
	double res=0;
	p.push_back(p[0]);
	for(int i=0;i<p.size()-1;i++){
		res+=crP(p[i],p[i+1]);
	}
	if(res<0) res*=-1;
	return res/2;
}

void print(Polygon p){
	for(int i=0;i<p.size();i++){
		printf("(%f,%f)\n",p[i].real(),p[i].imag());
	}
}

const double MY=2000;

double a[330][330];
double all=MY;

double ys[330][330];
int K;
int N;

void solve(int x){
	Polygon p;
	p.push_back(Point(x,0));
	p.push_back(Point(x+1,0));
	p.push_back(Point(x+1,MY));
	p.push_back(Point(x,MY));
//	printf("x=%d::\n",x);
	for(int i=0;i<N;i++){
		Point p1=Point(x,ys[i][x]);
		Point p2=Point(x+1,ys[i][x+1]);
		p=convexCut(p,p1,p2);
		a[i][x]=getArea(p);
//		printf("i=%d::\n",i);
//		print(p);
//		printf("area=%f\n",a[i][x]);
	}
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		for(int j=0;j<=K;j++){
			scanf("%lf",&ys[i][j]);
		}
	}
	for(int i=0;i<K;i++) solve(i);
	for(int i=0;i<N;i++){
		double ans=0;
		for(int j=0;j<K;j++){
			double tmp1=i==0?all:a[i-1][j];
			double tmp2=a[i][j];
			ans+=(tmp1-tmp2);
		}
		printf("%.9f\n",ans);
	}
	return 0;
}