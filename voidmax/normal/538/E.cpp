#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n;
vector <int> edge[200001];


pair <int, int> dfs1(int u, int deep) {
    if (edge[u].size() == 0) {
        return make_pair(1, 1);
    }
    vector <pair <int, int> > ans;
    int s = 0, sum1;
    For(i, 0, edge[u].size()) {
        ans.push_back(dfs1(edge[u][i], deep + 1));
        s += ans[i].second;
    }
    if (deep & 1) {
        int ans1 = 0;
        For(i, 0, ans.size()) {
            ans1 += ans[i].first - 1;
        }
        return make_pair(ans1 + 1, s);
    }
    else {
        int ans1 = 0;
        For(i, 0, ans.size()) {
            ans1 = max(ans1, s - ans[i].second + ans[i].first);
        }
        return make_pair(ans1, s);
    }
}

pair <int, int> dfs2(int u, int deep) {
    if (edge[u].size() == 0) {
        return make_pair(1, 1);
    }
    vector <pair <int, int> > ans;
    int s = 0;
    For(i, 0, edge[u].size()) {
        ans.push_back(dfs2(edge[u][i], deep + 1));
        s += ans[i].second;
    }
    if (deep & 1) {
        int ans1 = 1e9;
        For(i, 0, ans.size()) {
            ans1 = min(ans1, ans[i].first);
        }
        return make_pair(ans1, s);
    }
    else {
        int ans1 = 0;
        For(i, 0, ans.size()) {
            ans1 += ans[i].first;
        }
        return make_pair(ans1, s);
    }
}

main() {
    cin >> n;
    For(i, 0, n - 1)    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    cout << dfs1(1, 0).first << ' ' << dfs2(1, 0).first;
}