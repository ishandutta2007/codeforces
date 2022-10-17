#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                int a; cin >> a;
                if ((i+j)%2 != a%2) a++;
                cout << a << " "; 
            }
            cout << '\n';
        }
    }
}