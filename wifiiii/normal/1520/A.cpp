#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int f = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(s[i] == s[k] && s[i] != s[j]) f = 1;
                }
            }
        }
        cout << (!f ? "YES" : "NO") << '\n';
    }
}