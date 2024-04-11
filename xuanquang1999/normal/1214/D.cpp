#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MAXL = 1000005;

char tmp[MAXL];
void read(string &s) {
    scanf("%s", tmp);
    s.assign(tmp);
}

int n, m;
vector<string> s;
vector<vector<bool>> dp;

int main() {
    scanf("%d%d", &n, &m);

    s.resize(n);
    for(int i = 0; i < n; ++i)
        read(s[i]);

    dp.assign(n, vector<bool>(m, false));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (s[i][j] == '#')
                dp[i][j] = false;
            else
                dp[i][j] = (i > 0 && dp[i-1][j]) || (j > 0 && dp[i][j-1]);
        }
    }

    if (!dp[n-1][m-1]) {
        puts("0");
        return 0;
    }

    vector<vector<bool>> topRight(n, vector<bool>(m, false));
    vector<vector<bool>> bottomLeft(n, vector<bool>(m, false));
    int x, y;

    x = n-1; y = m-1;
    while (x > 0 || y > 0) {
        topRight[x][y] = true;
        if (x > 0 && dp[x-1][y])
            --x;
        else
            --y;
    }
    topRight[n-1][m-1] = false;

    x = n-1; y = m-1;
    while (x > 0 || y > 0) {
        bottomLeft[x][y] = true;
        if (y > 0 && dp[x][y-1])
            --y;
        else
            --x;
    }
    bottomLeft[n-1][m-1] = false;

    bool found = false;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if (topRight[i][j] && bottomLeft[i][j])
                found = true;

    puts((found) ? "1" : "2");

    return 0;
}