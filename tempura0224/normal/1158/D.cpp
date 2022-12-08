#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

using ld = double;
using Point =  complex<ld>;
const ld eps = 1e-7;
const ld pi = acos(-1.0);

bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}
//
ld dot(Point a, Point b) {
	return real(conj(a)*b);
}
//
ld cross(Point a, Point b) {
	return imag(conj(a)*b);
}
//
//
class Line {
public:
	Point a, b;
};
//
class Circle {
public:
	Point p;
	ld r;
};
//3
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps)return 1;//a,b,c
	if (cross(b, c) < -eps)return -1;//a,b,c
	if (dot(b, c) < 0)return 2;//c,a,b
	if (norm(b) < norm(c))return -2;//a,b,c
	return 0;//a,c,b
}
//2
bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}
//
bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a)*cross(l.b - l.a, s.b - l.a) < eps);
}
//
bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}
//
bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
//
bool isis_ss(Line s, Line t) {
	if (isis_sp(s, t.a) || isis_sp(s, t.b) || isis_sp(t, s.a) || isis_sp(t, s.b))return true;
	return(cross(s.b - s.a, t.a - s.a)*cross(s.b - s.a, t.b - s.a) < -eps && cross(t.b - t.a, s.a - t.a)*cross(t.b - t.a, s.b - t.a) < -eps);
}
//
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
//
//
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
//
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}
//
ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}
//
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}
//
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(p - r) : min(abs(p - s.a), abs(p - s.b));
}
//
ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t))return 0;
	return min({ dist_sp(s,t.a),dist_sp(s,t.b),dist_sp(t,s.a),dist_sp(t,s.b) });
}
int main(){
    int n;
    cin>>n;
    Point p[n];
    int st=-1,mi=inf;
    rep(i,n){
        double x,y;
        cin>>x>>y;
        p[i]={x,y};
        if(x<mi)st=i,mi=x;
    }
    vector<int> ans;
    vector<int> used(n);
    used[st]=1;
    ans.push_back(st);

    string s;
    cin>>s;
    rep(i,n-2){
        vector<int> ord(n);
        iota(ord.begin(),ord.end(),0);
        if(s[i]=='R'){
            sort(ord.begin(),ord.end(),[&](int x,int y){
                if(used[x])return false;
                if(used[y])return true;
                if(ccw(p[st],p[x],p[y])==-1)return true;
                return false;
            });
            st=ord[0];
            ans.push_back(st);
            used[st]=1;
        }
        else {
            sort(ord.begin(),ord.end(),[&](int x,int y){
                if(used[x])return false;
                if(used[y])return true;
                if(ccw(p[st],p[x],p[y])==1)return true;
                return false;
            });
            st=ord[0];
            ans.push_back(st);
            used[st]=1;
        }
    }
    rep(i,n)if(!used[i])ans.push_back(i);
    rep(i,n)cout<<ans[i]+1<<" ";
    return 0;
}