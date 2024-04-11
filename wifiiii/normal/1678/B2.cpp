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
        string s;
        cin >> s;
        int cnt = 0, seg = 0;
        char pre = 0;
        for(int i = 0; i < n; i += 2) {
            if(s[i] != s[i + 1]) {
                cnt += 1;
            } else {
                if(pre != s[i]) seg += 1;
                pre = s[i];
            }
        }
        if(seg == 0) ++seg;
        cout << cnt << ' ' << seg << '\n';
    }
}