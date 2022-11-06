#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
int a[maxn][6];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6; ++j) cin >> a[i][j];
    }
    vector<int> vec;
    for (int s = 0; s < pow(7, n); ++s) {
        vector<int> dig;
        int ns = s;
        for (int i = 0; i < n; ++i) {
            if (ns % 7) dig.push_back(a[i][ns % 7]);
            ns /= 7;
        }
        sort(dig.begin(), dig.end());
        do {
            int now = 0;
            if (dig.size() && dig[0] == 0) continue;
            for (int i = 0; i < dig.size(); ++i) now = now * 10 + dig[i];
            if (now > 0) vec.push_back(now);
        } while (next_permutation(dig.begin(), dig.end()));
    }
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int i = 0; i < vec.size(); ++i) {
        // cout << vec[i] << ' ';
        if (vec[i] != i + 1) return cout << i << endl, 0;
    }
    cout << vec[vec.size() - 1] << endl;
    return 0;
}