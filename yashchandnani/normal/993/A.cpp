#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator *(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-* this).cross(b-* this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to xaxis in interval [pi , pi ]
	double angle() const { return atan2(y, x); }
	P unit() const { return * this/dist(); } // makes d i s t ()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated a  radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
template <class P>
int segmentIntersection(const P& s1, const P& e1,
		const P& s2, const P& e2, P& r1, P& r2) {
	if (e1==s1) {
		if (e2==s2) {
			if (e1==e2) { r1 = e1; return 1; } // a l l equal
			else return 0; // d i f f e r e n t point segments
		} else return segmentIntersection(s2,e2,s1,e1,r1,r2);//swap
	}
	//segment directions and separation
	P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
	auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
	if (a == 0) { // i f p a r a l l e l
		auto b1=s1.dot(v1), c1=e1.dot(v1),
			 b2=s2.dot(v1), c2=e2.dot(v1);
		if (a1 || a2 || max(b1,min(b2,c2))>min(c1,max(b2,c2)))
			return 0;
		r1 = min(b2,c2)<b1 ? s1 : (b2<c2 ? s2 : e2);
		r2 = max(b2,c2)>c1 ? e1 : (b2>c2 ? s2 : e2);
		return 2-(r1==r2);
	}
	if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
	if (0<a1 || a<-a1 || 0<a2 || a<-a2)
		return 0;
	r1 = s1-v1*a2/a;
	return 1;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	pii x[4],y[4];
	int max_x=-101,min_x=101,max_y=-101,min_y=101,mxy=-209,nxy=209,mxy2=-209,nxy2=209;
	Point<double> p1[4],p2[4],a,b;
	rep(i,4) {
		cin>>x[i].fst>>x[i].snd;
		p1[i].x = x[i].fst,p1[i].y = x[i].snd;
		max_x=  max(max_x,x[i].fst);
		min_x = min(min_x,x[i].fst);
		max_y=  max(max_y,x[i].snd);
		min_y = min(min_y,x[i].snd);
	}
	bool f = 0;
	rep(i,4) {
		cin>>y[i].fst>>y[i].snd;
		p2[i].x=y[i].fst,p2[i].y = y[i].snd;
		if(min_x<=y[i].fst&&y[i].fst<=max_x&&y[i].snd>=min_y&&y[i].snd<=max_y) f=1;
		mxy=  max(mxy,y[i].fst+y[i].snd);
		nxy = min(nxy,y[i].fst+y[i].snd);
		mxy2=  max(mxy2,y[i].fst-y[i].snd);
		nxy2 = min(nxy2,y[i].fst-y[i].snd);
	}
	rep(i,4){
		if(mxy>=x[i].fst+x[i].snd&& nxy<=x[i].fst+x[i].snd && mxy2>=x[i].fst-x[i].snd && nxy2<= x[i].fst-x[i].snd) f=1;
	}
	rep(i,4){
		rep(j,4){
			if(segmentIntersection(p1[i],p1[(i+1)%4],p2[j],p2[(j+1)%4],a,b)>0) {
				f = 1;
			}
		}
	}

	if(f) cout<<"YES";
	else cout<<"NO";
	return 0;
}