#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=65;

double p[MAXN][MAXN];
double last[MAXN], dp[MAXN], winl[MAXN], win[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<1<<n;++i) for (int j=0;j<1<<n;++j) cin >> p[i][j], p[i][j]/=100;
    for (int i=0;i<1<<n;++i) win[i]=1;
    for (int r=1;r<=n;++r){
        swap(last,dp); ms(dp,0);
        swap(winl,win); ms(win,0);
        int sz=(1<<r-1);
        for (int i=0;i<1<<n;++i){
            if ((i/sz)%2==0){
                double chance=0;

                for (int j=(i/sz+1)*sz;j<(i/sz+2)*sz;++j){
                    win[i]+=winl[i]*p[i][j]*winl[j];
                    dp[i]=max(dp[i],last[i]+last[j]);
                }
                dp[i]+=sz*win[i];
            }
            if ((i/sz)%2==1){
                double chance=0;
                for (int j=(i/sz-1)*sz;j<(i/sz)*sz;++j){
                    win[i]+=winl[i]*p[i][j]*winl[j];
                    dp[i]=max(dp[i],last[i]+last[j]);
                }
                dp[i]+=sz*win[i];
            }
        }
    }
    double ans=0;
    for (int i=0;i<1<<n;++i) ans=max(dp[i],ans);
    cout << fixed << setprecision(9) << ans << '\n';
}