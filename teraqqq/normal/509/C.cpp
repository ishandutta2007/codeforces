#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int B = 301;
const int T = 1000;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string s(T, '0');

    for (int iter = n; iter--; ) {
        int b; cin >> b;

        // cout << "I need " << b << endl;

        vector<array<int, 10>> go(2*T+2);
        for (auto& u : go) fill(u.begin(), u.end(), -1);

        for (int i = 2*T; i--; ) {
            if (i & 1) {
                fill(go[i].begin(), go[i].end(), i+2);
            } else {
                const int x = s[i/2] - '0';
                go[i][x] = i + 2;
                for (int j = x + 1; j < 10; ++j) go[i][j] = i + 3;
            }
        }

        vector<bitset<B>> dp(2*T+2);
        for (auto& u : dp) u.reset();

        dp[2*T+1][0] = true;
        for (int i = 2*T; i--; ) {
            for (int j = 0; j < 10; ++j) if (go[i][j] >= 0) dp[i] |= dp[go[i][j]] << j;
        }

        string t(T, '0');
        for (int i = 0, v = 0; i < T; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (go[v][j] < 0) continue;
                if (dp[go[v][j]][b - j]) {
                    t[i] = j + '0';
                    b -= j;
                    v = go[v][j];
                    break;
                }
            }
        }

        s = t;
        for (int i = 0, w = 0; i < T; ++i) {
            if (s[i] == '0') {
                if (w) cout << '0';
            } else {
                cout << s[i];
                w = 1;
            }
        }
        cout << endl;
    }
}