#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[maxn+5][maxn+5],mx[7][maxn+5],id[100005],N;
int a[maxn+5],num[maxn+5];

void upd(int &x,int y) {if(y>x) x=y;}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) if(id[a[i]]==0) id[a[i]]=++N,num[N]=a[i];
    rep(i,1,n)
    {
        vi tmp(N+1,0);
        int ID=id[a[i]];
        rep(A,1,N) 
        {
            if(id[a[i]-1]) upd(tmp[A],dp[A][id[a[i]-1]]+1);
            if(id[a[i]+1]) upd(tmp[A],dp[A][id[a[i]+1]]+1);
            upd(tmp[A],mx[a[i]%7][A]+1);
        }
        rep(A,1,N) 
        {
            upd(dp[A][ID],tmp[A]);
            upd(dp[ID][A],tmp[A]);
            upd(mx[num[A]%7][ID],tmp[A]);
            upd(mx[a[i]%7][A],tmp[A]);
        }
    }
    int ans=0;
    rep(A,1,N) rep(B,1,N) upd(ans,dp[A][B]);
    printf("%d\n",ans);
    return 0;
}