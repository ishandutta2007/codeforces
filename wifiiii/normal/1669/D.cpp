#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto check = [&](string a) -> int {
            if(a.empty()) return 1;
            if(a.size() == 1) return 0;
            vector<int> cnt(2);
            for(char c : a) {
                if(c == 'R') ++cnt[0];
                else ++cnt[1];
            }
            return cnt[0] && cnt[1];
        };
        string a;
        int ok = 1;
        for(char c : s) {
            if(c == 'W') {
                if(!check(a)) ok = 0;
                a.clear();
            } else {
                a += c;
            }
        }
        if(!check(a)) ok = 0;
        cout << (ok ? "YES" : "NO") << '\n';
    }
}