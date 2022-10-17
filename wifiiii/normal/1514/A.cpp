#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int ok = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int sq = sqrt(x);
            if(sq * sq != x) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}