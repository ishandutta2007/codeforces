#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int nTest;
int r, c, k;
char s[MAXN][MAXN], ans[MAXN][MAXN];
vector<char> ch;

int main() {
    for(char c = 'a'; c <= 'z'; ++c)
        ch.push_back(c);
    for(char c = 'A'; c <= 'Z'; ++c)
        ch.push_back(c);
    for(char c = '0'; c <= '9'; ++c)
        ch.push_back(c);

    scanf("%d", &nTest);
    for(int iTest = 0; iTest < nTest; ++iTest) {
        scanf("%d%d%d", &r, &c, &k);
        for(int i = 0; i < r; ++i)
            scanf("%s", &s[i]);

        int cnt = 0;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if (s[i][j] == 'R')
                    ++cnt;

        vector<int> f(k, 0);
        for(int i = 0; i < cnt; ++i)
            ++f[i%k];

        int rice = 0, chicken = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int x = i, y = j;
                if (x%2 == 1)
                    y = c - y - 1;
                ans[x][y] = ch[chicken];
                if (s[x][y] == 'R')
                    ++rice;
                if (chicken < k-1 && rice == f[chicken]) {
                    chicken++;
                    rice = 0;
                }
            }
            ans[i][c] = 0;
        }

        for(int i = 0; i < r; ++i)
            printf("%s\n", ans[i]);
    }

    return 0;
}