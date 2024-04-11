#include<cstdio>
#include<cmath>
#include<complex>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef complex<Real> Vector;

const Real PI=acos(-1.0);

Real getRnd(){
	long long val=0;
	for(int i=0;i<12;i++){
		int tmp=rand()%10;
		val=val*10+tmp;
	}
	Real r=(Real)val/(1e12);
	return 2+18*r;
//	if(large) return 4+36*r;
//	else return 2+18*r;
}

set<Real> ls;

vector<Point> poly;

int N;

void rot(Vector &v){
	v*=Point(cos(-PI*2/N),sin(-PI*2/N));
}

Vector fitLen(Vector v,Real l){
	Real tmp=abs(v);
	Real r=l/tmp;
	return v*r;
}

void solve(){
	if(N<=4){
		printf("No solution\n");
		exit(0);
	}
	Point p=Point(0,0);
	Vector v=Point(1,0);
	poly.push_back(p);
	for(int i=0;i<N-1;i++){
		Real l;
		while(true){
			l=getRnd();
			set<Real>::iterator it=ls.lower_bound(l);
			if(it!=ls.end()&&(*it)/l<1.002) continue;
			if(it!=ls.begin()){
				it--;
				if(l/(*it)<1.002) continue;
			}
			break;
		}
		if(N%2==0){
			if(i==(N-1)/2){
				l=900;
			}
		}else{
			if(i==(N-1)/2-1){
				l=900;
			}else if(i==(N-1)/2){
				l=899;
			}
		}
		ls.insert(l);
		rot(v);
		Vector vec=fitLen(v,l);
		if(i==N-2){
			Real num=-p.imag();
			Real den=vec.imag();
			vec*=max(1.0,num/den);
		}
		p+=vec;
		poly.push_back(p);
	}
	if(poly.back().imag()>0){
		Point d=Point(0,poly.back().imag());
		for(int i=0;i<poly.size();i++){
			poly[i]-=d;
		}
		Vector v=poly[0]-poly[1];
		Real num=-poly[1].imag();
		Real den=v.imag();
		v*=(num/den);
		poly[0]=poly[1]+v;
	}
	Point val=poly[0];
	for(int i=0;i<poly.size();i++){
		poly[i]-=val;
	}
	if(poly.back().real()>-2){
		Real val=poly.back().real()+2;
		if(N%2==0){
			for(int i=N/2;i<N;i++){
				poly[i]-=val;
			}
		}
	}
	Real Ma=0;
	for(int i=0;i<N;i++){
		Ma=max(Ma,abs(poly[i].real()));
		Ma=max(Ma,abs(poly[i].imag()));
	}
	Real num=9e5;
	Real den=max(9e5,Ma);
	for(int i=0;i<N;i++){
		poly[i]*=(num/den);
	}
	Ma=0;
	for(int i=0;i<N;i++){
		Point p1=poly[i];
		Point p2=poly[(i+1)%N];
		Real l=abs(p1-p2);
		Ma=max(Ma,l);
	}
	Real coe=min(999.0,Ma)/Ma;
	for(int i=0;i<N;i++){
		poly[i]*=coe;
	}
}

int main(){
	scanf("%d",&N);
	solve();
	for(int i=N-1;i>=0;i--){
		printf("%f %f\n",poly[i].real(),poly[i].imag());
	}
	return 0;
}