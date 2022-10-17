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
        n -= 2;
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int found = 0;
        for(int i = 0; i <= n; ++i) {
            for(string x : vector<string> {"aa", "ab", "ba", "bb"}) {
                auto b = a;
                b.insert(b.begin() + i, x);
                int ok = 1;
                for(int j = 1; j < b.size(); ++j) {
                    if(b[j][0] != b[j-1][1]) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    for(int j = 0; j < b.size(); ++j) {
                        cout << b[j][0];
                    }
                    cout << b.back()[1] << '\n';
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
    }
}