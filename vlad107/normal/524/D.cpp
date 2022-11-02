#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<pair<int, int>> e[N];
int col[N];
set<pair<int, int>> s0;
int cnt_col, n, m, k, bal;
map<int, int> cnt;

void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0) bal--;
}

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) bal++;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int hh = (s[0] - '0') * 10 + s[1] - '0';
        int mm = (s[3] - '0') * 10 + s[4] - '0';
        int ss = (s[6] - '0') * 10 + s[7] - '0';
        int tt = hh * 3600 + mm * 60 + ss;
        e[tt].push_back(make_pair(i, +1));
        e[tt + k].push_back(make_pair(i, -1));
    }
    bal = 0;
    bool found = false;
    for (int i = 0; i < 86400; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            if (e[i][j].second == -1) {
                s0.erase(make_pair(i - k, e[i][j].first));
                del(col[e[i][j].first]);
            } 
        }
        for (int j = 0; j < e[i].size(); j++) {
            if (e[i][j].second == 1) {
                if (bal < m) {
                    col[e[i][j].first] = cnt_col++;
                    add(cnt_col - 1);
                    s0.insert(make_pair(i, e[i][j].first));
                } else {
                    auto it = s0.end();
                    --it;
                    col[e[i][j].first] = col[it->second];
                    s0.insert(make_pair(i, e[i][j].first));
                    add(col[e[i][j].first]);
                }
            }
        }
        if (bal == m) found = true;
    }
    if (!found) {
        puts("No solution");
        return 0;
    }
    printf("%d\n", cnt_col);
    for (int i = 0; i < n; i++) printf("%d\n", col[i] + 1);
}