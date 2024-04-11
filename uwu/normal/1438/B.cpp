#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<int> s;
        bool flag=0;
        for (int i=1;i<=n;++i) {
            int a; cin >> a;
            if (s.count(a)) flag=1;
            s.insert(a);
        }
        cout << (flag?"YES":"NO") << '\n';
    }
}