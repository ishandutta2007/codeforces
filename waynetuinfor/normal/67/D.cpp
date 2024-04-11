#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int posx[maxn], posy[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1, x; i <= n; ++i) cin >> x, posx[x] = i;
    for (int i = 1, y; i <= n; ++i) cin >> y, posy[y] = i;
    vector<int> a;
    for (int i = 1; i <= n; ++i) a.push_back(i);
    sort(a.begin(), a.end(), [&](const int &i, const int &j) { return posx[i] > posx[j]; });
    vector<int> lis; lis.push_back(posy[a[0]]);
    for (int i = 1; i < n; ++i) {
        if (posy[a[i]] > lis.back()) lis.push_back(posy[a[i]]);
        else *lower_bound(lis.begin(), lis.end(), posy[a[i]]) = posy[a[i]];
    }
    cout << (int)lis.size() << endl;
    return 0;
}