#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int A[maxn+5][maxn+5];
ll a[maxn+5],b[maxn+5];
ll M;

bool check(int n,int m)
{
    rep(i,2,n)
    {
        int diff=inf;
        rep(j,1,m)
        {
            int t=A[i][j]-A[i-1][j];
            if(diff==inf) diff=t;
            else if(diff!=t)
            {
                if(1ll*diff*t>=0) return 0;
                if(M==0)
                {
                    M=abs(diff)+abs(t);
                }
                else if(M!=abs(diff)+abs(t)) return 0;
            }
        }
        a[i]=diff;
    }
    rep(j,2,m)
    {
        int diff=inf;
        rep(i,1,n)
        {
            int t=A[i][j]-A[i][j-1];
            if(diff==inf) diff=t;
            else if(diff!=t)
            {
                if(1ll*diff*t>=0) return 0;
                if(M==0)
                {
                    M=abs(diff)+abs(t);
                }
                else if(M!=abs(diff)+abs(t)) return 0;
            }
        }
        b[j]=diff;
    }
    b[1]=A[1][1];
    if(M==0) M=1ll<<40;
    rep(i,2,n) a[i]=a[i-1]+(a[i]<0?M+a[i]:a[i]);
    rep(i,2,m) b[i]=b[i-1]+(b[i]<0?M+b[i]:b[i]);
    rep(i,1,n) rep(j,1,m) if((a[i]+b[j])%M!=A[i][j]) return 0;
    return 1;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%d",&A[i][j]);
    bool f=check(n,m);
    if(f==0) puts("NO");
    else
    {
        puts("YES");
        printf("%I64d\n",M);
        rep(i,1,n) printf("%I64d%c",a[i]," \n"[i==n]);
        rep(i,1,m) printf("%I64d%c",b[i]," \n"[i==m]);
    }
    return 0;
}