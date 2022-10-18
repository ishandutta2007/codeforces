#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int n, m;
string s[MAXN];

int main() {
//    freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> s[i];

    vector<int> ord;
    for(int i = 1; i <= n; ++i)
        ord.push_back(i);

    auto cmp = [&] (int x, int y) {
//        cout << s[x] << " " << s[y] << endl;
        for(int i = 0; i < m; ++i) {
            if (s[x][i] != s[y][i]) {
                return (s[x][i] < s[y][i]) != (i&1);
            }
        }
        return false;
    };

    sort(ord.begin(), ord.end(), cmp);

    for(int x: ord)
        printf("%d ", x);

    return 0;
}