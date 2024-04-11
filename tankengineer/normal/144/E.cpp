#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 100005;

int x[N], y[N], ord[N];

bool by_x(int i, int j) {
    return x[i] > x[j];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", x + i, y + i);
        ord[i] = i;
    }
    sort(ord, ord + m, by_x);
    vector<int> ans;
    priority_queue<pair<int, int> > heap;
    int p = 0;
    for (int i = n; i >= 1; --i) {
        while (p < m && x[ord[p]] == i) {
            heap.push(make_pair(-y[ord[p]], ord[p]));
            ++p;
        }
        while (heap.size()) {
            int u = heap.top().second;
            heap.pop();
            if (n - y[u] + 1 > i) {
                continue;
            } else {
                ans.push_back(u);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d%c", ans[i] + 1, " \n"[i == (int)ans.size() - 1]);
    }
    return 0;
}