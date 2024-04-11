#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, m, a[N];

vector<int> val[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", a + i);
        --a[i];
        val[a[i]].push_back(i);
    }
    long long ori = 0, ans;
    for (int i = 0; i + 1 < m; ++i) {
        ori += abs(a[i] - a[i + 1]);
    }
    ans = ori;
    for (int i = 0; i < n; ++i) {
        long long tmp = ori;
        vector<int> cur;
        for (int j = 0; j < (int)val[i].size(); ++j) {
            int u = val[i][j];
            if (u && a[u - 1] != a[u]) {
                tmp -= abs(a[u] - a[u - 1]);
                cur.push_back(a[u - 1]);
            }
            if (u + 1 < m && a[u + 1] != a[u]) {
                tmp -= abs(a[u] - a[u + 1]);
                cur.push_back(a[u + 1]);
            }
        }
        if (cur.size() == 0) {
            continue;
        }
        sort(cur.begin(), cur.end());
        int next = cur[cur.size() / 2];
        for (int j = 0; j < (int)cur.size(); ++j) {
            tmp += abs(cur[j] - next);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}