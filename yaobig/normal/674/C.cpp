#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const db eps=1e-9;
int cmp(db x) {return (x>eps)-(x<-eps);}

struct P
{
    db x,y;
    P(){}
    P(db a,db b):x(a),y(b){}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}q[maxn+5];
int cross(P a,P b) {return cmp((db)a.x*b.y-(db)a.y*b.x);}

int t[maxn+5];
ll s[maxn+5];
db A[maxn+5],B[maxn+5];

db dp[2][maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&t[i]);
    rep(i,1,n) s[i]=s[i-1]+t[i];
    rep(i,1,n) A[i]=A[i-1]+(db)s[i]/t[i];
    rep(i,1,n) B[i]=B[i-1]+1.0/t[i];

    rep(i,1,n) dp[0][i]=1e30;
    rep(r,1,k)
    {
        int front=0,rear=-1;
        q[++rear]=P(0,0);
        rep(i,1,n)
        {
            while(front<rear && cross(q[front+1]-q[front],P(1,B[i]))>=0) front++;
            dp[r&1][i]=q[front].y-B[i]*q[front].x+A[i];
            P tmp(s[i],dp[r-1&1][i]-A[i]+s[i]*B[i]);
            while(front<rear && cross(tmp-q[rear],q[rear]-q[rear-1])>=0) rear--;
            q[++rear]=tmp;
        }
    }
    printf("%.7f\n",dp[k&1][n]);

    return 0;
}