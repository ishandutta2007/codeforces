#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int a = 0, b = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') ++a;
            if(s[i]=='[') ++b;
            if(s[i]==')') {
                if(a) {
                    ++ans;
                    --a;
                }
                else a = 0;
            }
            if(s[i]==']') {
                if(b) {
                    ++ans;
                    --b;
                }
                else b = 0;
            }
        }
        cout << ans << "\n";
    }
}