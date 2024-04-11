#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<string> s(h + 2);
        for (int i = 1; i <= h; i++) {
            cin >> s[i];
            s[i] = "#" + s[i] + "#";
        }
        s[0] = s[h + 1] = string(w + 2, '#');
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, 1, 0, -1};
        int r = -1;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= w; j++) {
                if (s[i][j] == 'L') {
                    r = i * (w + 2) + j;
                }
            }
        }
        queue<int> que;
        que.emplace(r);
        while (!que.empty()) {
            int i = que.front() / (w + 2);
            int j = que.front() % (w + 2);
            que.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + di[dir];
                int nj = j + dj[dir];
                if (s[ni][nj] != '.') {
                    continue;
                }
                int ways = 0;
                int oks = 0;
                for (int dir2 = 0; dir2 < 4; dir2++) {
                    int nni = ni + di[dir2];
                    int nnj = nj + dj[dir2];
                    if (s[nni][nnj] == '.') {
                        ways++;
                    } else if (s[nni][nnj] != '#') {
                        ways++;
                        oks++;
                    }
                }
                if (oks > 0 && ways <= oks + 1) {
                    s[ni][nj] = '+';
                    que.emplace(ni * (w + 2) + nj);
                }
            }
        }
        for (int i = 1; i <= h; i++) {
            s[i].pop_back();
            s[i].erase(s[i].begin());
            cout << s[i] << '\n';
        }
    }
    return 0;
}