#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double

template<typename T> struct pt{ T x,y;pt(T _x=0, T _y=0):x(_x),y(_y){}};
template<typename T> pt<T> operator - (pt<T> a, pt<T> b){ return pt<T>(a.x-b.x,a.y-b.y);}
template<typename T> pt<T> operator + (pt<T> a, pt<T> b){ return pt<T>(a.x+b.x,a.y+b.y);}
template<typename T> pt<ldb> operator / (pt<T> a, T b){ return pt<T>((ldb)a.x/b,(ldb)a.y/b);}
template<typename T, typename F> pt<ldb> operator / (pt<T> a, F b){ return pt<T>((ldb)a.x/b,(ldb)a.y/b);}
template<typename T> T cross(pt<T> a, pt<T> b){ return a.x*b.y-a.y*b.x;}
template<typename T> T dot(pt<T> a, pt<T> b){ return a.x*b.x+a.y*b.y;}
template<typename T> T sq(pt<T> a){ return dot(a,a);}
template<typename T> ldb abs(pt<T> a){ return sqrt(sq(a));}
template<typename T> ldb dist(pt<T> a, pt<T> b){ return abs(a-b);}
template<typename T> T Manhattan(pt<T> a, pt<T> b){ return abs(a.x-b.x)+abs(a.y-b.y);}
template<typename T, typename F> T Manhattan(pt<T> a, pt<F> b){ return abs(a.x-b.x)+abs(a.y-b.y);}

template<typename T> struct line
{
	pt<T> v;T c;
	line(pt<T> a, pt<T> b):v(b-a),c(cross(v,a)){}
	line(T a, T b, T _c):v(b,-a),c(-_c){}
};
template<typename T> T side(line<T> a, pt<T> b){ return a.c-cross(a.v,b);}
template<typename T> T sgn(T x){ return x==0?0:x/abs(x);}
template<typename T> T sside(line<T> a, pt<T> b){ return sgn(side(a,b));}
template<typename T> bool parallel(line<T> a, line<T> b){ return cross(a.v,b.v)==0;}
template<typename T> pt<ldb> inter(line<T> a, line<T> b){ return pt<ldb>((ldb)(b.c*a.v.x-a.c*b.v.x),(ldb)(b.c*a.v.y-a.c*b.v.y))/cross(b.v,a.v);}

template<typename T> struct seg{ pt<T> a,b;seg(pt<T> _a, pt<T> _b):a(_a),b(_b){}};
template<typename T> bool sec(line<T> a, seg<T> b){ return sside(a,b.a)*sside(a,b.b)<=0;}
template<typename T> pt<ldb> inter(line<T> a, seg<T> b){ line<T> c(b.a,b.b);return inter(a,c);}

int main()
{
	pt<ldb> A,B,C,D;
	ldb a,b,c;
	//scanf("%i %i %i",&a,&b,&c);
	cin>>a>>b>>c;
	line<ldb> l(a,b,c);
	//scanf("%lld %lld %lld %lld",&A.x,&A.y,&B.x,&B.y);
	cin>>A.x>>A.y>>B.x>>B.y;
	C=pt<ldb>(A.x,B.y);
	D=pt<ldb>(B.x,A.y);
	ldb ans=Manhattan(A,B);
	vector<pt<ldb>> work;
	//cout<<sside(l,A)<<" "<<sside(l,B)<<"\n";
	//cout<<l.v.x<<"*y-"<<l.v.y<<"*x="<<l.c<<"\n";
	if(sec(l,seg<ldb>(A,C)) && !parallel(l,line<ldb>(A,C))) work.push_back(inter(l,line<ldb>(A,C)));
	if(sec(l,seg<ldb>(A,D)) && !parallel(l,line<ldb>(A,D))) work.push_back(inter(l,line<ldb>(A,D)));
	if(sec(l,seg<ldb>(B,C)) && !parallel(l,line<ldb>(B,C))) work.push_back(inter(l,line<ldb>(B,C)));
	if(sec(l,seg<ldb>(B,D)) && !parallel(l,line<ldb>(B,D))) work.push_back(inter(l,line<ldb>(B,D)));
	for(int i=0;i<work.size();i++)
	{
		//cout<<"("<<work[i].x<<", "<<work[i].y<<")\n";
		for(int j=0;j<work.size();j++)
		{
			if(i==j) continue;
			ans=min(ans,dist(work[i],work[j])+Manhattan(work[i],A)+Manhattan(work[j],B));
		}
	}
	cout<<fixed<<setprecision(12)<<ans<<"\n";
	return 0;
}