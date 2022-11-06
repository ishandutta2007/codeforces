#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> v) {
    vector<int> l = { v[0] };
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > l.back()) l.push_back(v[i]);
        else *lower_bound(l.begin(), l.end(), v[i]) = v[i];
    }
    return l.size();
}

int lds(vector<int> v) {
    reverse(v.begin(), v.end());
    return lis(v);
}

int n;

int cal(int x) {
    return x + (n + x - 1) / x;
}

int main() {
    cin >> n;
    int m = 1;
    for (int i = 2; i <= n; ++i) {
        if (cal(i) < cal(m)) m = i;
    } 
    int t = n % m;
    for (int i = t; i >= 1; --i) cout << i << ' ';
    for (int i = t + m; i <= n; i += m) {
        for (int j = i, k = 0; k < m; --j, ++k) cout << j << ' ';
    }
    cout << endl;
}