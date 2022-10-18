#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n;
vector<pair<int, int>> p;
vector<vector<int>> adj;
vector<int> num;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int d; scanf("%d", &d);
        p.push_back({d, i+1});
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    for(int i = 0; i < p[0].first; ++i) {
        bool expanded = false;
        while (adj.size() <= i + p[i].first) {
            adj.push_back(vector<int>());
            num.push_back(-1);
            expanded = true;
        }

        int u = 2*p[i].second - 1, v = u + 1;

//        printf("%d %d %d\n", i, u, v);
//
//        for(int i = 0; i < adj.size(); ++i) {
//            printf("num: %d\n", num[i]);
//            printf("adj:");
//            for(int u: adj[i])
//                printf(" %d", u);
//            puts("");
//        }

        num[i] = u;
        if (expanded)
            num[i + p[i].first] = v;
        else
            adj[i + p[i].first - 1].push_back(v);
    }

    vector<pair<int, int>> edges;

    for(int i = p[0].first; i < n; ++i) {
        int u = 2*p[i].second - 1, v = u + 1;
        if (p[i].first == 1) {
            edges.push_back({u, v});
            edges.push_back({num[0], u});
        } else {
            adj[0].push_back(u);
            adj[p[i].first - 2].push_back(v);
        }
    }

    for(int i = 0; i < adj.size(); ++i) {
        for(int u: adj[i])
            edges.push_back({num[i], u});
        if (i > 0)
            edges.push_back({num[i-1], num[i]});
    }

    for(pair<int, int> e: edges)
        printf("%d %d\n", e.first, e.second);

    return 0;
}