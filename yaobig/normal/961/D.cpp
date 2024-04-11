#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct P
{
    int x,y;
    P():x(0),y(0){}
    P(int a,int b):x(a),y(b){}
    void in() {scanf("%d%d",&x,&y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
};
ll cross(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}

bool check(P a,P b,vector<P> A)
{
    vector<P> B;
    for(auto p: A) if(cross(p-a,b-a)!=0) B.pb(p);
    if(B.size()<=2) return 1;
    for(auto p: B) if(cross(p-B[0],B[1]-B[0])!=0) return 0;
    return 1;
}

int main()
{
    int n; scanf("%d",&n);
    vector<P> p(n);
    rep(i,0,n-1) p[i].in();
    if(n<=4) return puts("YES"),0;
    if(check(p[0],p[1],p)) return puts("YES"),0;
    if(check(p[0],p[2],p)) return puts("YES"),0;
    if(check(p[1],p[2],p)) return puts("YES"),0;
    puts("NO");
    return 0;
}