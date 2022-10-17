#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        // n * a + k * b
        string s;
        cin >> s;
        if(b >= 0) {
            cout << n * a + n * b << '\n';
        } else {
            int cnt = 1;
            for(int i = 1; i < n; ++i) {
                if(s[i] != s[i-1]) {
                    ++cnt;
                }
            }
            cout << n * a + (cnt / 2 + 1) * b << '\n';
        }
    }
}