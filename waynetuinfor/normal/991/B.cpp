#include <bits/stdc++.h>
using namespace std;

int eval(vector<int> v) {
    int all = accumulate(v.begin(), v.end(), 0);
    double avg = all * 1.0 / v.size();
    return round(avg + 1e-9);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; ++i) {
        vector<int> tv(v.begin(), v.end());
        for (int j = 0; j < i; ++j) tv[j] = 5;
        if (eval(tv) == 5) {
            cout << i << endl;
            return 0;
        }
    }
}