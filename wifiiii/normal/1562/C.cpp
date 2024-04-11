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
        string s;
        cin >> s;
        int m = n / 2;
        for(int i = 0; i < m; ++i) {
            if(s[i] == '0') {
                cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
                goto ok;
            }
        }
        for(int i = n - m; i < n; ++i) {
            if(s[i] == '0') {
                cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
                goto ok;
            }
        }
        cout << 1 << " " << m << " " << n - m + 1 << " " << n << endl;
        ok:;
    }
}