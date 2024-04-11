#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const db eps=1e-1;
int cmp(db x) {return (x>eps)-(x<-eps);}

struct P
{
    ll x,y;
    P(){}
    P(ll a,ll b):x(a),y(b){}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}q[maxn+5];
int cross(P a,P b) {return cmp((db)a.x*b.y-(db)a.y*b.x);}

int a[maxn+5],b[maxn+5];
ll dp[maxn+5];
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    int front=0,rear=-1;
    dp[1]=0;
    q[++rear]=P(-b[1],dp[1]);
    rep(i,2,n)
    {
        while(front<rear && cross(q[front+1]-q[front],P(1,a[i]))>=0) front++;
        dp[i]=q[front].y-q[front].x*a[i];
        P tmp(-b[i],dp[i]);
        while(front<rear && cross(tmp-q[rear],q[rear]-q[rear-1])>=0) rear--;
        q[++rear]=tmp;
    }
    printf("%I64d\n",dp[n]);
    return 0;
}