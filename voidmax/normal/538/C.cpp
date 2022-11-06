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
#define int long long

using namespace std;

int n, m;
vector <pair <int, int> > ans;
int cnt = 0;

main() {
    //freopen("input.txt", "r", stdin);
    //freopen("", "r", stdin);freopen("", "w", stdout);
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        ans.push_back(make_pair(a, b));
    }
    For(i, 0, m - 1) {
        if (ans[i + 1].first - ans[i].first < abs(ans[i + 1].second - ans[i].second)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        int L = 0, R = ans[i + 1].first - ans[i].first + 1;
        while (R - L > 1) {
            int M = (R + L) >> 1;
            ans[i].first += M;
            ans[i].second += M;
            if (ans[i + 1].first - ans[i].first >= abs(ans[i + 1].second - ans[i].second)) {
                L = M;
            }
            else {
                R = M;
            }
            ans[i].first -= M;
            ans[i].second -= M;
        }
        cnt = max(cnt, ans[i].second + L);
    }
    pair <int, int> need = ans[0];
    cnt = max(cnt, need.first + need.second - 1);
    need = ans[(int)ans.size() - 1];
    need.first = n - need.first + 1;
    cnt = max(cnt, need.first + need.second - 1);
    cout << cnt;
}