#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

map<int,pii> M;
struct P
{
    ll x,y;
    P():x(0),y(0){}
    P(ll a,ll b):x(a),y(b){}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
};
ll cross(P a,P b) {return a.x*b.y-a.y*b.x;}

int main()
{
    rep(i,0,300) rep(j,i,300) if(i+j!=0 && M.find(i*i+j*j)==M.end()) M[i*i+j*j]={i,j};
    int n; scanf("%d",&n);
    vector<pair<int,pii>> A;
    for(auto x: M) A.pb(x);
    A.resize(n+1);
    ll S=0;
    rep(i,0,n-1) S+=A[i].FI;
    if(S&1)
    {
        per(i,0,n-1) if((A[n].FI-A[i].FI)&1)
        {
            swap(A[i],A[n]); break;
        }
    }
    A.resize(n);
    assert(A[0].SE.FI==0 && A[0].SE.SE==1);
    S=0;
    for(auto [l,it]: A) S+=it.FI;
    if(S&1) swap(A[0].SE.FI,A[0].SE.SE);
    sort(A.begin(),A.end(),[](pair<int,pii> a,pair<int,pii> b){return a.SE.FI>b.SE.FI;});
    S=0;
    for(auto &it: A)
    {
        int &x=it.SE.FI;
        if(S>0) x=-x,S+=x;
        else S+=x;
    }
    assert(S==0);
    sort(A.begin(),A.end(),[](pair<int,pii> a,pair<int,pii> b){return a.SE.SE>b.SE.SE;});
    for(auto &it: A)
    {
        int &y=it.SE.SE;
        if(S>0) y=-y,S+=y;
        else S+=y;
    }
    assert(S==0);
    vector<P> p;
    for(auto [l,it]: A) p.pb(P(it.FI,it.SE));
    sort(p.begin(),p.end(),[](P a,P b)
    {
        bool upa=a.y>0 || (a.y==0 && a.x<0);
        bool upb=b.y>0 || (b.y==0 && b.x<0);
        if(upa!=upb) return upa<upb;
        return cross(a,b)>0;
    });
    //for(auto a: p) printf("? %lld %lld\n",a.x,a.y);
    puts("YES");
    P s(0,0);
    for(auto a: p)
    {
        s=s+a;
        printf("%lld %lld\n",s.x,s.y);
    }
    return 0;
}