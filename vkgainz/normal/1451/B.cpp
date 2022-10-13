#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int q; cin >> q;
        string s; cin >> s;
        while(q--) {
            int l, r; cin >> l >> r;
            --l, --r;
            bool w = 0;
            for(int i=0;i<l;i++) {
                if(s[i]==s[l]) w = 1;
            }
            for(int i=r+1;i<n;i++) {
                if(s[i]==s[r]) w = 1;
            }
            if(w==1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}