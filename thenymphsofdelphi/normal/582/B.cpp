#include <bits/stdc++.h>
using namespace std;
 
const int N = 100 + 5;
int n, T, a[N];
 
vector <int> build(int t) {
    vector <int> res(n * t);
    for (int i = 0; i < n * t; ++i)
        res[i] = (i < n) ? a[i] : res[i - n];
    return res;
}
 
vector <int> calc_lis(vector <int> a) {
    int n = a.size();
    vector <int> res(n), dp(n + 1, 500);
    dp[0] = -1;
    for (int i = 0; i < n; ++i) {
            res[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[ res[i] ] = a[i];
    }
    return res;
}
 
int main() {
    cin >> n >> T;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    if (T <= 2 * n) {
        vector <int> A = build(T);
        A = calc_lis(A);
        for (int i = 0; i < n * T; ++i)
            res = max(res, A[i]);
    } else {
        vector <int> A = build(n);
        vector <int> inc = calc_lis(A);
        for (int i = 0; i < n * n; ++i) 
            A[i] = 301 - A[i];
        reverse(A.begin(), A.end());
        vector <int> dec = calc_lis(A);
        reverse(dec.begin(), dec.end());
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (a[i] == a[j]) cnt++;
            for (int j = 0; j < n; ++j) {
                if (a[j] < a[i]) continue;
                res = max(res, inc[(n - 1) * n + i] + cnt * (T - 2 * n) + dec[j]);
            }
        }           
    }
    cout << res << endl;
    return 0;
}