#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=11;

int a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            cin >> a[i];
        }
        set<int> s;
        for (int i=0;i<(1<<n);++i){
            int tot=0;
            for (int j=1;j<=n;++j){
                if (1&(i>>(j-1))) tot+=a[j];
            }
            s.insert(tot);
        }
        if (s.size()!=(1<<n)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }    
}