#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int N = 2e5+7;
const int INF = 1e9;

int cnt[N][26];

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s; int k2 = k>>1;
    for(int i = 0; i < n; i += k) {
        const int j = i+k-1;
        for(int t = 0; i+t < j-t; ++t)
            cnt[t][s[i+t]-'a']++, cnt[t][s[j-t]-'a']++;
        if(k%2) cnt[k][s[i+k2]-'a']++;
    }

    int res = n;
    for(int i = 0; i <= k; ++i) {
        int add = 0, sum = 0;
        for(int j = 0; j < 26; ++j) {
            ckmax(add, cnt[i][j]), sum += cnt[i][j];
        }
        res -= add;
    }

    for(int i = 0; i < n; i += k) {
        const int j = i+k-1;
        for(int t = 0; i+t < j-t; ++t)
            cnt[t][s[i+t]-'a']--, cnt[t][s[j-t]-'a']--;
        if(k%2) cnt[k][s[i+k2]-'a']--;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}