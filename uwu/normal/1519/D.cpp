#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5005;

ll psa[MAXN][MAXN];
ll a[MAXN], b[MAXN], pre[MAXN], suf[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            psa[i][j]=a[i]*b[j]+psa[i-1][j+1];
        }
    }
    for (int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i]*b[i];
    for (int i=n;i>=1;--i) suf[i]=suf[i+1]+a[i]*b[i];
    ll ans=0;
    for (int r=1;r<=n;++r){
        for (int l=r;l>=1;--l){
            ans=max(ans,pre[l-1]+suf[r+1]+psa[r][l]-psa[l-1][r+1]);
        }
    }
    cout << ans << '\n';
}