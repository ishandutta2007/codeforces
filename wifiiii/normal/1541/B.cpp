#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), ra(2*n+1, -1);
        for(int i = 0; i < n; ++i) cin >> a[i], ra[a[i]] = i;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(1ll * a[i] * a[i] == i + i + 2) --ans;
            for(int aj = 1; aj * a[i] <= 2 * n; ++aj) {
                if(ra[aj] != -1 && aj * a[i] == i + 1 + ra[aj] + 1) ++ans;
            }
        }
        cout << ans / 2 << '\n';
    }
}