#include <bits/stdc++.h>
//#define int long long

using namespace std;

int maxi = 0;

void rec(vector <int> a, int pos, int cur = 0) {
    if (pos == -1) {
        if (!a.empty()) cur++;
        maxi = max(maxi, cur);
        return;
    }
    vector <int> left, right;
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] & (1 << pos)) right.push_back(a[i]);
        else left.push_back(a[i]);
    }
    if (left.size() == 0 || right.size() == 0) {
        rec(a, pos - 1, cur);
        return;
    }
    rec(left, pos - 1, cur + 1);
    rec(right, pos - 1, cur + 1);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    rec(a, 30);
    cout << n - maxi << endl;
    return 0;
}