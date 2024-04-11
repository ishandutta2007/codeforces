#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 20000
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
    int x,y,id;
    P():x(0),y(0){}
    P(int a,int b):x(a),y(b){}
    void in() {int a,b; scanf("%d%d",&a,&b); x=a; y=b;}
    //void out() {printf("? %.6f %.6f\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}p[maxn+5];

int cross(P a,P b) {return a.x*b.y-a.y*b.x;}

int match[maxn+5];
int n; 

void solve(int l,int r)
{
    if(l>r) return;
    int idx=min_element(p+l,p+r+1,[](P a,P b){
        if(a.y!=b.y) return a.y<b.y;
        return a.x<b.x;
    })-p;
    swap(p[l],p[idx]);
    sort(p+l+1,p+r+1,[c=p[l]](P a,P b){
        return cross(a-c,b-c)>0;
    });
    int cl=p[l].id>n,diff=0;
    rep(i,l+1,r)
    {
        int ci=p[i].id>n;
        if(cl^ci && diff==0)
        {
            match[p[l].id]=p[i].id;
            match[p[i].id]=p[l].id;
            solve(l+1,i-1);
            solve(i+1,r);
            return;
        }
        diff+=ci?1:-1;
    }
    assert(0);
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n*2) p[i].in(),p[i].id=i;
    solve(1,n*2);
    rep(i,1,n) printf("%d\n",match[i]-n);
    return 0;
}