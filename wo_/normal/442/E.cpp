#include<cstdio>
#include<complex>
#include<cmath>
#include<vector>
#include<cassert>
#include<utility>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef complex<Real> Vector;
typedef pair<Point,Point> Line;
typedef pair<Point,Point> Segment;

const Real eps=1e-11;
const Real PI=acos(-1);

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

Real normalize(Real x){
	while(x<-PI) x+=PI*2;
	while(x>PI) x-=PI*2;
	if(x<=-PI) x+=PI*2;
	return x;
}

struct Circle:vector<Real>{
	Point c;
	Real r;
	Circle(){}
	Circle(Point c_,Real r_){
		c=c_;
		r=r_;
	}
	Point getPoint(Real ang){
		return c+r*Point(cos(ang),sin(ang));
	}
};

Real doP(Vector a,Vector b){
	return (conj(a)*b).real();
}

Vector proj(Point p,Vector b){
	return b*doP(p,b)/norm(b);
}

Point perp(Line l,Point a){
	Point p=l.first,q=l.second;
	return p+proj(a-p,q-p);
}

void iCL(Circle &c,Line l){
	Point h=perp(l,c.c);
	Real d=abs(h-c.c);
	if(eq_(c.r,d)){
		//accept tangent
		Real ang=arg(h-c.c);
		c.push_back(ang);
	}else if(eq_(d,(Real)0)){
		Point p=l.first;
		if(eq_(p,c.c)) p=l.second;
		Real ang=arg(p-c.c);
		c.push_back(normalize(ang));
		c.push_back(normalize(ang+PI));
	}else if(lt_(d,c.r)){
		Real ang=arg(h-c.c);
		Real ang2=acos(d/(c.r));
		c.push_back(normalize(ang+ang2));
		c.push_back(normalize(ang-ang2));
	}
}

typedef pair<Real,int> P;

Point ps[1010];
int N;
Real W,H;
Line es[4];
/*
bool check2(Real R,int id){
	Point ps2[4]={Point(0,0),Point(W,0),Point(W,H),Point(0,H)};
	for(int i=0;i<4;i++){
		if(le_(R,abs(ps[id]-ps2[i]))) return true;
	}
	return false;
}*/

bool isin_(Point p){
	Real x=p.real(),y=p.imag();
	return le_((Real)0,x)&&le_(x,W)&&le_((Real)0,y)&&le_(y,H);
}

bool check(Real R,int id){
	if(eq_(R,(Real)0)) return true;
	Circle c=Circle(ps[id],R);
	for(int i=0;i<4;i++){
		iCL(c,es[i]);
	}/*
	if(c.size()==0){
		Point tmp=ps[id]+Point(R,0);
		if(!isin_(tmp)) return false;
	}*/
	vector<P> vec;
	for(int i=0;i<N;i++){
		if(i==id) continue;
		if(eq_(ps[i],ps[id])) continue;
		Real d=abs(ps[i]-ps[id]);
		if(le_(R*2,d)) continue;
		Real ang1=arg(ps[i]-ps[id]);
		Real ang2=acos(d/(R*2));
		Real lb=normalize(ang1-ang2);
		Real ub=normalize(ang1+ang2);
		if(lb>ub){
			vec.push_back(P(-PI,1));
			vec.push_back(P(ub,-1));
			vec.push_back(P(lb,1));
			vec.push_back(P(PI,-1));
		}else{
			vec.push_back(P(lb,1));
			vec.push_back(P(ub,-1));
		}
	}
	for(int i=0;i<c.size();i++){
		vec.push_back(P(c[i],0));
	}
	vec.push_back(P(-PI,0));
	vec.push_back(P(PI,0));
	sort(vec.begin(),vec.end());
	int cnt=0;
	for(int i=0;i<(int)vec.size()-1;i++){
		cnt+=vec[i].second;
		if(cnt<=1){
			if(lt_(vec[i].first,vec[i+1].first)){
				Real ang=(vec[i].first+vec[i+1].first)/2;
				Point p=c.getPoint(ang);
				if(isin_(p)) return true;
			}
		}
	}
	return false;
}

bool check(Real R){
	for(int i=0;i<N;i++){
		bool flg=check(R,i);
		if(flg) return true;
	}
	return false;
}

void input(){
	int w,h;
	scanf("%d%d%d",&w,&h,&N);
	W=w;
	H=h;
	Point ps2[]={Point(0,0),Point(W,0),Point(W,H),Point(0,H)};
	for(int i=0;i<4;i++) es[i]=Segment(ps2[i],ps2[(i+1)%4]);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ps[i]=Point(x,y);
	}
}

Real solve(){
	Real lb=0,ub=1e7;
	srand(time(NULL));
	for(int i=1;i<N;i++){
		int j=rand()%(i+1);
		swap(ps[i],ps[j]);
	}
	for(int i=0;i<N;i++){
		bool flg=check(lb*(1.0+eps),i);
		if(!flg) continue;
		ub=1e7;
		if(!flg) continue;
		while(ub/lb>(1+eps)){
			Real mid=(ub+lb)/2;
			bool flg=check(mid,i);
			if(flg) lb=mid;
			else ub=mid;
		}
	}
	return lb;
}
	/*	
	for(int stage=0;stage<100;stage++){
		Real mid=(ub+lb)/2;
		bool flg=check(mid);
		if(flg) lb=mid;
		else ub=mid;
	}
	return ub;
}*/

int main(){
	input();
	Real ans=solve();
	printf("%.12f\n",(double)ans);
	return 0;
}