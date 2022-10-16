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

struct P
{
    ll x,y;
    P(){}
    P(ll a,ll b):x(a),y(b){}
    P operator -(const P a) const {return P(x-a.x,y-a.y);}
}p[maxn+5];
int cross(P a,P b)
{
    db v1=(db)b.y/b.x;
    db v2=(db)a.y/a.x;
    if(v1==v2) return 0;
    return v1>v2?1:-1;
}

int q[maxn+5];
ll dp[2][maxn+5];
int dis[maxn+5],a[maxn+5];
ll S[maxn+5];
int cnt[maxn+5];

vi T;

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,2,n) scanf("%d",&dis[i]);
    rep(i,2,n) dis[i]+=dis[i-1];
    rep(i,1,m)
    {
        int h,t; scanf("%d%d",&h,&t);
        a[i]=t-dis[h];
    }
    T.pb(-inf);
    rep(i,1,m) T.pb(a[i]);
    sort(T.begin(),T.end());
    T.erase(unique(T.begin(),T.end()),T.end());
    int N=T.size()-1;
    rep(i,1,m)
    {
        int id=lower_bound(T.begin(),T.end(),a[i])-T.begin();
        S[id]+=T[id];
        cnt[id]++;
    }
    rep(i,1,N) S[i]+=S[i-1];
    rep(i,1,N) cnt[i]+=cnt[i-1];
    rep(i,1,N) dp[0][i]=1ll<<60;
    rep(r,1,k)
    {
        p[0]=P(cnt[0],dp[r-1&1][0]+S[0]);
        int front=0,rear=-1;
        q[++rear]=0;
        rep(i,1,N)
        {
            while(front<rear && cross(p[q[front+1]]-p[q[front]],P(1,T[i]))>=0) front++;
            int j=q[front];
            dp[r&1][i]=dp[r-1&1][j]+1ll*(cnt[i]-cnt[j])*T[i]-(S[i]-S[j]);
            p[i]=P(cnt[i],dp[r-1&1][i]+S[i]);
            while(front<rear && cross(p[i]-p[q[rear]],p[q[rear]]-p[q[rear-1]])>=0) rear--;
            q[++rear]=i;
        }
    }
    printf("%I64d\n",dp[k&1][N]);
    return 0;
}