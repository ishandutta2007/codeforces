#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int nTest, n, x;
vector<int> tree[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &x);
        for(int u = 1; u <= n; ++u)
            tree[u].clear();

        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        if (tree[x].size() <= 1) 
            puts("Ayush");
        else {
            int cnt = n - 3;
            puts((cnt%2) ? "Ayush" : "Ashish");
        }
    }


    return 0;
}