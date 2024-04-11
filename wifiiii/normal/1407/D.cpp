#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int a[300005], dp[300005];
int stk[300005], tp=0;
const int maxn = 300005;
int st[2][maxn][22];
int querymx(int l,int r)
{
   int k = 31 - __builtin_clz(r-l+1);
   return max(st[0][l][k],st[0][r-(1<<k)+1][k]);
}
int querymn(int l,int r)
{
    int k = 31 - __builtin_clz(r-l+1);
    return min(st[1][l][k],st[1][r-(1<<k)+1][k]);
}
void init(int n)
{
    for(int i=1;i<=n;++i) st[0][i][0]=st[1][i][0]=a[i];
    for(int j=1;j<=21;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            st[0][i][j]=max(st[0][i][j-1],st[0][i+(1<<(j-1))][j-1])
            ,st[1][i][j]=min(st[1][i][j-1],st[1][i+(1<<(j-1))][j-1]);
}
int lmx[300005], lmn[300005];
int main() {
    int n;
    cin>>n;
    ii cin>>a[i];
    init(n);
    memset(dp,0x3f,sizeof(dp));
    tp = 0;
    for(int i=1;i<=n;++i) {
        while(tp && a[stk[tp]] >= a[i]) --tp;
        if(tp) lmn[i] = stk[tp];
        else lmn[i] = 0;
        stk[++tp] = i;
    }
    tp = 0;
    for(int i=1;i<=n;++i) {
        while(tp && a[stk[tp]] <= a[i]) --tp;
        if(tp) lmx[i] = stk[tp];
        else lmx[i] = 0;
        stk[++tp] = i;
    }
    dp[1] = 0;
    for(int i=2;i<=n;++i) {
        dp[i] = min(dp[i], dp[i-1]+1);
        if(a[i-1] < a[i]) {
            int p = lmx[i-1];
            while(p && querymx(p+1, i-1) < min(a[p], a[i])) {
                dp[i] = min(dp[i], dp[p]+1);
                p = lmx[p];
            }
        } else if(a[i-1] > a[i]){
            int p = lmn[i-1];
            while(p && querymn(p+1, i-1) > max(a[p], a[i])) {
                dp[i] = min(dp[i], dp[p]+1);
                p = lmn[p];
            }
        }
    }
    cout << dp[n] << endl;
}