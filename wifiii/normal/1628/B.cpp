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
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        auto rev = [&](string s) {
            reverse(s.begin(), s.end());
            return s;
        };
        auto get = [&](const string &s) -> int {
            int ret = 0;
            for(char c : s) {
                ret = ret * 26 + c - 'a';
            }
            return ret;
        };
        auto solve = [&]() -> int {
            vector<int> vis3(26 * 26 * 26), vis2(26 * 26);
            for(string s : a) {
                if(s == string(s.rbegin(), s.rend())) return 1;
                if(s.size() == 3) {
                    if(vis3[get(rev(s))]) return 1;
                    vis3[get(s)] = 1;
                    vis2[get(s.substr(0, 2))] = 1;
                } else if(s.size() == 2) {
                    if(vis2[get(rev(s))]) return 1;
                    vis2[get(s)] = 1;
                    for(int i = 0; i < 26; ++i) {
                        vis3[get(s) * 26 + i] = 1;
                    }
                }
            }
            return 0;
        };
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}