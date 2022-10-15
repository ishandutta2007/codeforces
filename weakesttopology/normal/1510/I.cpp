#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bernoulli_distribution coin(0.5);
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    int score = 0;
    for (int j = 0; j < m; ++j) {
        string s;
        cin >> s;
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] < score) {
                sum += -1 + 2 * (s[i] - '0');
                ++cnt;
            }
        }
        char ch = abs(sum) >= cnt / 3 ? (sum >= 0 ? '1' : '0') : (coin(rng) ? '1' : '0');
        cout << ch << endl;
        char res;
        cin >> res;
        score += res != ch;
        for (int i = 0; i < n; ++i) {
            b[i] += s[i] != res;
        }
    }
    exit(0);
}