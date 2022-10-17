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
        vector<int> neg, pos, zero;
        int tot=0, sn=0, sp=0;
        for (int i=1,a;i<=n;++i){
            cin >> a; tot+=a;
            if (a==0) zero.push_back(a);
            else if (a>0) pos.push_back(a), sp+=a;
            else neg.push_back(a), sn+=a;
        }
        if (tot==0) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            if (-sn>sp){
                for (int x:neg) cout << x << " ";
                for (int x:pos) cout << x << " ";
                for (int x:zero) cout << x << " ";
            }
            else{
                for (int x:pos) cout << x << " ";
                for (int x:neg) cout << x << " ";
                for (int x:zero) cout << x << " ";
            }
            cout << '\n';
        }
    }
}