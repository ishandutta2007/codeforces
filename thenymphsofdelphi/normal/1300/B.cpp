#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 2e5 + 5;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q; while (q--){
        cin >> n;
        for (int i = 1; i <= 2 * n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + 2 * n);
        cout << abs(a[n] - a[n + 1]) << endl;
        continue;
    }
}