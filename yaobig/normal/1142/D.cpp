#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];
int dp[maxn+5][11];

int main()
{
    int tran[11]={};
    int sum=0;
    rep(i,1,11)
    {
        tran[i%11]=(9+sum)%11;
        sum+=i;
    }

    scanf("%s",s+1);
    int n=strlen(s+1);
    ll ans=0;
    rep(i,1,n) 
    {
        int x=s[i]-'0';
        if(x!=0) dp[i][x]++;
        rep(j,x+1,10) dp[i][(tran[j]+1+x)%11]+=dp[i-1][j];
        rep(j,0,10) ans+=dp[i][j];
    }
    printf("%lld\n",ans);
    return 0;
}