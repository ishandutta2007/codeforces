#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i=1;i<=k;++i) cout << (char)('a'+k%3);
        for (int i=k+1;i<=n;++i) cout << (char)('a'+i%3);
        cout << '\n';
    }
}