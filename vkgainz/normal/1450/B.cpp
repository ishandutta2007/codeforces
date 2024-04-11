#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> p(n);
        for(int i=0;i<n;i++) cin >> p[i]. f>> p[i].s;
        bool win = false;
        for(int i=0;i<n;i++) {
            int num = 0;
            for(int j=0;j<n;j++) {
                if(abs(p[j].f-p[i].f)+abs(p[j].s-p[i].s) <=k)
                    ++num;
            }
            if(num==n) win = true;
        }
        if(win) cout << 1 << "\n";
        else cout << -1 << "\n";
    }
}