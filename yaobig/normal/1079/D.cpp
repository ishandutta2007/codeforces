#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct P
{
    db x,y;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {scanf("%lf%lf",&x,&y);}
    void out() {printf("%.10f %.10f\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    db len() const {return sqrt(x*x+y*y);}
    db dot(const P &b) const {return x*b.x+y*b.y;}
    db cross(const P &b) const {return x*b.y-y*b.x;}
};

int main()
{
    int a,b,c,x1,x2,y1,y2; scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d",&x1,&y1);
    scanf("%d%d",&x2,&y2);
    db ans = fabs(x1-x2) + fabs(y1-y2);

    if(a!=0 && b!=0)
    {
        auto getP = [&](int x,int y)
        {
            vector<P> res;
            db y2 = ((db)a*x+c)/(db)(-b);
            res.pb(P(x,y2));
            db x2 = ((db)b*y+c)/(db)(-a);
            res.pb(P(x2,y));
            return res;
        };
        auto A = getP(x1,y1);
        auto B = getP(x2,y2);
        for(auto p: A) for(auto q: B)
        {
            chmin(ans,(P(x1,y1)-p).len()+(p-q).len()+(q-P(x2,y2)).len());
        }
    }
    printf("%.10f\n",ans);
    return 0;
}