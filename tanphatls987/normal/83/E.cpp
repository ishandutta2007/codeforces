#include <bits/stdc++.h>

using namespace std;

vector<int> f[21];


const int inf = 1e9 + 10;
const int N = 2e5 + 10;


int n, m;
string s[N];
int psum[N];
int p2[21];
int cost(string s1, string s2) {
    int com = m;
    while (com && s1.substr(m - com, com) != s2.substr(0, com)) com--;
    return m - com;
}
void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> s[i];

    m = s[1].size();

    p2[0] = 1;
    for(int i = 1; i <= 20; i++) p2[i] = p2[i - 1] * 2;

    psum[1] = m;
    for(int i = 2; i <= n; i++) 
        psum[i] = psum[i - 1] + cost(s[i - 1], s[i]);

    f[0].push_back(inf);
    for(int i = 1; i <= m; i++) {
        f[i] = vector<int>(1 << i, inf);    
    }
    
}

int ans[N];
int solve() {
    ans[0] = inf;
    s[0] = string(m, '0');

    for(int i = 1; i < n; i++) {
        int cost = m + psum[i];
        for(int j = 0, tail = 0; ; j++) {
            cost = min(f[j][tail] + psum[i] + m - j, cost);
            if (j == m) break;
            tail += p2[j] * (s[i + 1][j] - '0');
        }
        ans[i] = cost;
        for(int j = 0, head = 0; ; j++) {
            f[j][head] = min(f[j][head], ans[i] - psum[i + 1]);
            if (j == m) break;
            head = head * 2 + s[i][m - j - 1] - '0';
        }
    }
    return min(0, f[0][0]) + psum[n];
}
int main() {
    prepare();
    cout << solve();
}