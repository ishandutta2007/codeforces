#include<cstdio>
#include<cmath>
#include<complex>
#include<utility>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef complex<Real> Vector;
typedef pair<Point,Point> Line;
typedef pair<Point,Point> Segment;

const Real eps=1e-9;

void print(Point p,char ch='\n'){
	printf("(%f %f)%c",p.real(),p.imag(),ch);
}

template<class T> bool eq_(T a,T b){
	return abs(a-b)<eps;
}

template<class T> bool lt_(T a,T b){
	if(eq_(a,b)) return false;
	return a<b;
}

template<class T> bool le_(T a,T b){
	if(eq_(a,b)) return true;
	return a<b;
}

Real doP(Vector a,Vector b){
	return (conj(a)*b).real();
}

Real crP(Vector a,Vector b){
	return (conj(a)*b).imag();
}

Vector proj(Point p,Vector b){
	return b*doP(p,b)/norm(b);
}

Point perp(Line l,Point a){
	Point p=l.first,q=l.second;
	return p+proj(a-p,q-p);
}

Point iLL(Line la,Line lb){
	//not parallel here
	Point a1=la.first,a2=la.second;
	Point b1=lb.first,b2=lb.second;
	Real num=crP(b1-a1,a2-a1);
	Real den=crP(a2-a1,b2-b1);
	return b1+(b2-b1)*(num/den);
}

Vector toVec(Line l){
	return l.second-l.first;
}

Line ls[3030];
int N;

Point origin=Point(0,0);

Real calc(int id){
	Real res=0;
	Real sum=0;
	Point h=perp(ls[id],origin);
	if(eq_(h,origin)) return 0;
	for(int i=1;i<N;i++){
		int j=(id+i)%N;
		Point p=iLL(ls[id],ls[j]);
		Real a=crP(h,p);
		res+=(a*(i-1)-sum);
		sum+=a;
	}
	return res/2;
}

Vector toVec2(Line l){
	Vector v=toVec(l);
	if(eq_(v.imag(),(Real)0)){
		if(lt_(v.real(),(Real)0)){
			v=Vector(-v.real(),v.imag());
		}
		return v;
	}
	if(lt_(v.imag(),(Real)0)){
		v*=-1;
	}
	return v;
}

bool cmp(const Line &l1,const Line &l2){
	Vector v1=toVec2(l1);
	Vector v2=toVec2(l2);
	return arg(v1)<arg(v2);
}

Real solve(){
	sort(ls,ls+N,cmp);
	Real sum=0;
	for(int i=0;i<N;i++){
		sum+=calc(i);
	}
	Real den=(Real)N*(N-1)*(N-2)/6;
	return sum/den;
}

Line getL(Real a,Real b,Real c){
	//ax+by=c;
	if(eq_(a,(Real)0)){
		Point p1=Point(0,c/b);
		Point p2=Point(1,c/b);
		return Line(p1,p2);
	}else{
		Point p1=Point(c/a,0);
		Point p2=Point((c-b)/a,1);
		return Line(p1,p2);
	}
}

void input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ls[i]=getL(a,b,c);
	}
}

int main(){
	input();
	Real ans=solve();
	printf("%f\n",(double)ans);
	return 0;
}