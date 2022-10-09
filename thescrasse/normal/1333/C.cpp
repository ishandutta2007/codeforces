#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, s;
map<long long, long long> boh;
vector<pair<long long, long long>> segm;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i + 2];
    }

    segm.push_back({1, 1});

    boh[0] = 1;
    k = 0;
    for (i = 2; i <= n + 1; i++) {
        k += a[i];
        if (boh[k] == 0) {
            boh[k] = i;
        } else {
            segm.push_back({i, boh[k] + 1});
            boh[k] = i;
        }
    }

    res = 0;
    s = segm.size();

    for (i = 1; i < s; i++) {
        segm[i].second = max(segm[i].second, segm[i - 1].second);
    }

    res = (n * (n + 1)) / 2;
    for (i = 1; i < s; i++) {
        res -= (n + 2 - segm[i].first) * (segm[i].second - segm[i - 1].second);
    }

    cout << res;

    return 0;
}