#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50005;

const int M = 27 * 27 * 27 * 27;

int m;
vector<int> appear[M];

const int LOG = 15;

int getname(int &l) {
    char buf[5];
    scanf("%s", buf);
    l = strlen(buf);
    int ret = 0;
    for (int i = 0; i < l; ++i) {
        ret = ret * 27 + buf[i] - 'a' + 1;
    }
    return ret;
}

int n;
char s[50005];

int main() {
    scanf("%s", s);
    n = strlen(s);  
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j = 0; j < 4 && j + i < n; ++j) {
            tmp = tmp * 27 + s[i + j] - 'a' + 1;
            appear[tmp].push_back(i);
        }
    }
    int m;
    scanf("%d", &m);
    map<pair<int, int>, int> mem;
    while (m--) {
        int l0, l1;
        int u = getname(l0), v = getname(l1);
        if (appear[u].size() > appear[v].size() || appear[u].size() == appear[v].size() && u > v) {
            swap(u, v);
            swap(l0, l1);
        }
        if (mem.count(make_pair(u, v))) {
            printf("%d\n", mem[make_pair(u, v)]);
            continue;
        }
        int ans = N + 1;
        if (appear[u].size() * LOG < appear[u].size() + appear[v].size()) {
            for (int i = 0; i < (int)appear[u].size(); ++i) {
                int p = appear[u][i],
                    qq = lower_bound(appear[v].begin(), appear[v].end(), p) - appear[v].begin(),
                    q;
                if (qq < appear[v].size()) {
                    q = appear[v][qq];
                    ans = min(ans, max(p + l0, q + l1) - p);
                }
                if (qq > 0) {
                    q = appear[v][qq - 1];
                    ans = min(ans, max(p + l0, q + l1) - q);
                }
            }
        } else {
            int i = 0, j = 0;
            while (i < appear[u].size() && j < appear[v].size() && ans != max(l0, l1)) {
                int p = appear[u][i], q = appear[v][j];
                ans = min(ans, max(p + l0, q + l1) - min(p, q));
                if (p < q) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }
        if (ans == N + 1) {
            ans = -1;
        }
        mem[make_pair(u, v)] = ans;
        printf("%d\n", ans);
    }
    return 0;
}