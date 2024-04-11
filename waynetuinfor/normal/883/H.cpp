#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
string s;
vector<int> odd, p;
int cnt[1000], n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    string s; cin >> s;
    // for (int i = 1; i <= sqrt(n); ++i) {
        // if (n % i == 0) p.push_back(i), p.push_back(nn / i);
    // }
    // sort(p.begin(), p.end());
    for (int i = 0; i < s.length(); ++i) ++cnt[s[i]];
    for (int i = 0; i < 1000; ++i) {
        if (cnt[i] & 1) odd.push_back(i), --cnt[i];
    }
    if (odd.size() == 0) {
        int ptr = 0;
        while (cnt[ptr] == 0) ++ptr;
        string ans = "";
        for (int i = 0; i < n / 2; ++i) {
            ans += (char)(ptr);
            cnt[ptr] -= 2;
            while (cnt[ptr] == 0) ++ptr;
        }
        cout << 1 << endl;
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        return 0;
    }
    int c = odd.size();
    int ptr = 0;
    while (cnt[ptr] == 0) ++ptr;
    // for (int i : odd) cout << i << ' '; cout << endl;
    while (n % c || (n % c == 0 && (n / c) % 2 == 0)) {
        c += 2;
        cnt[ptr] -= 2;
        odd.push_back(ptr); odd.push_back(ptr);
        while (cnt[ptr] == 0) ++ptr;
    }
    cout << odd.size() << endl;
    int len = n / (int)odd.size();
    for (int i : odd) {
        string ans = "";
        for (int j = 0; j < (len - 1) / 2; ++j) {
            ans += (char)(ptr);
            cnt[ptr] -= 2;
            while (cnt[ptr] == 0) ++ptr;
        }
        cout << ans; cout << (char)(i);
        reverse(ans.begin(), ans.end());
        cout << ans << ' ';
    }
    return 0;
}