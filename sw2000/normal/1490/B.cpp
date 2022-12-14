#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<ll, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(0) * 2;
const double eps = 1e-8;
int sgn(double x) {return x <= -eps ? -1 : (x < eps ? 0 : 1);}
inline double sqr(double x) {return x * x;}
/******************************************************************/
struct Point
{
    double x, y;
    void i(){cin>>x>>y;}
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    bool operator==(Point b) {return !sgn(x - b.x) && !sgn(y - b.y);}
    Point operator+(Point b) {return Point(x + b.x, y + b.y);}
    Point operator-(Point b) {return Point(x - b.x, y - b.y);}
    Point operator*(double k) {return Point(x * k, y * k);}
    Point operator/(double k) {return Point(x / k, y / k);}
    bool operator < (Point b)const {return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;}
//	a^b bb
    double operator^(Point b) {return x * b.y - y * b.x;}
//	,
    double operator*(Point b) {return x * b.x + y * b.y;}
//	
    double len2() {return x * x + y * y;}
//    
    double len() {return sqrt(len2());}
    double dis(Point p) {return (*this - p).len();}
//	papb
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }
//	r
    Point trunc(double r)
    {
        double l = len();
        if(!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }
//     90 
    Point rotleft() {return Point(-y, x);}
//     90 
    Point rotright() {return Point(y, -x);}
//    pangle
    Point rotate(Point p, double angle)
    {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};
struct Line
{
    //
    Point s, e;
    Line() {}
    Line(Point _s, Point _e): s(_s), e(_e) {}
//    
//    2 
//    1 (
//    0 
    int segcrosseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e-s));
        int d3 = sgn((v.e-v.s) ^ (s - v.s));
        int d4 = sgn((v.e-v.s) ^ (e - v.s));
        if((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.e-s) * (v.e-e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    //
    //
    Point crosspoint(Line v)
    {
        double a1 = (v.e-v.s) ^ (s - v.s);
        double a2 = (v.e-v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
}l[1010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        int n,c[3]{};
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            c[a%3]++;
        }
        int ans=0;
        for(int i=0;i<3;i++)
        {
            ans+=max(0,max(c[i]-n/3,n/3-c[(i+1)%3]));
        }
        cout<<ans<<endl;
    }
    return 0;
}