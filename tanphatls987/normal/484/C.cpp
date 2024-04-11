#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
int pa[N][22];
int psum[N];

int n;
string s, news;
int get(int x, int lv) {
    x = x + n;
    for(int i = 0; lv; i++, lv >>= 1) if (lv & 1){ 
        x = pa[x][i];
    }
    return x - n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.length();
    news.resize(n);

    int m = int(log2(n));
    for(int j = 0; j <= m; j++)
        for(int i = 1; i < n; i++) pa[i][j] = i - (1 << j);
    int test;
    cin >> test;
    while (test--) {
        int k, d;
        cin >> k >> d;
        for(int i = 0; i < d; i++) {
            psum[i + 1] = psum[i] + (k + d - i - 1) / d;
        }
        
        for(int i = 0; i < k; i++) {
            pa[n + i][0] = n + (psum[i % d] + i / d) - 1;
        }
        for(int j = 1; j <= m; j++)
            for(int i = n; i < n + k; i++) pa[i][j] = pa[pa[i][j - 1]][j - 1];
        for(int i = 0; i < n; i++) {
            int ini_pos = min(i, k - 1);
            int turn = n - max(i, k - 1);
            int pos = i - ini_pos + get(ini_pos, turn) + turn;
            news[pos] = s[i];
        }
        s = news;
        cout << s << '\n';
    }
}