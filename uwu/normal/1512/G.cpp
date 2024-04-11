#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e7+1;

ll tot[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n=1e7;
    ms(ans,-1);
    for (int i=1;i<=n;++i){
        for (int j=i;j<=n;j+=i) tot[j]+=i;
        if (tot[i]<=n&&ans[tot[i]]==-1) ans[tot[i]]=i;
    }
    int t; cin >> t;
    while (t--){
        int c; cin >> c;
        cout << ans[c] << '\n';
    }
}