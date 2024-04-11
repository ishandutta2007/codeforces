#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int eq = 0, zr = 0, nz = 0;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x == 0) zr = 1;
            else nz++;
            if(s.count(x)) eq = 1;
            s.insert(x);
        }
        if(zr || eq) cout << nz << '\n';
        else cout << nz + 1 << '\n';
    }
}