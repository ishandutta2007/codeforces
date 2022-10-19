#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/05, 23:56:24
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int deg[5001];
vector<int> redge[5001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        ans.push_back((x < y) + 1);
        ++deg[x];
        redge[y].push_back(x);
    }
    vector<int> st;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) st.push_back(i);
    }
    for (int i = 0; i < st.size(); ++i) {
        int x = st[i];
        for (int j : redge[x]) {
            if (--deg[j] == 0) st.push_back(j);
        }
    }
    if (st.size() < n) {
        printf("2\n");
        for (int i : ans) printf("%d ", i);
    }
    else {
        printf("1\n");
        for (int i = 0; i < m; ++i) printf("1 ");
    }
    return 0;
}