#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5005;

ll cnt[MAXN][MAXN], ways[MAXN], val[MAXN], tot;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q; cin >> n >> k >> q;
    for (int i=1;i<=n;++i) cnt[0][i]=1;
    for (int i=1;i<=k;++i){
        for (int j=1;j<=n;++j){
            cnt[i][j]=cnt[i-1][j-1]+cnt[i-1][j+1], cnt[i][j]%=mod;
        }
    }
    for (int i=0;i<=k;++i){
        for (int j=1;j<=n;++j){
            ways[j]+=cnt[i][j]*cnt[k-i][j]%mod, ways[j]%=mod;
        }
    }
    for (int i=1;i<=n;++i) cin >> val[i], tot+=ways[i]*val[i]%mod, tot%=mod;
    for (int i=1;i<=q;++i){
        int idx, x; cin >> idx >> x;
        tot-=ways[idx]*val[idx]%mod; tot+=mod; tot%=mod;
        val[idx]=x;
        tot+=ways[idx]*val[idx]%mod, tot%=mod;
        cout << tot << '\n';
    }
}