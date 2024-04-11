#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        set<int> s;
        for (int i=1,a;i<=n;++i){
            cin >> a;
            s.insert(a);
        }
        if (s.size()>k){
            cout << -1 << '\n';
            continue;
        }
        int idx=1;
        while (s.size()<k){
            if (!s.count(idx)) s.insert(idx);
            idx++;
        }
        cout << k*n << '\n';
        for (int i=1;i<=n;++i){
            for (int x:s){
                cout << x << " ";
            }
        }
        cout << '\n';
    }
}