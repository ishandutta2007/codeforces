/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int sm[5001][5001];

int main()
{
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
    }
    vector<int> f(30);
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ++j;
        }
        ++f[j];
    }
    while (q--) {
        long long b; cin >> b;
        int ans = 0;
        for (int i = 29; i >= 0; i--) {
            if ((1 << i) * 1LL * f[i] <= b) {
                ans += f[i];
                b -= (1 << i) * 1LL * f[i];
            } else {
                int take = b / (1 << i);
                ans += take;
                b -= take * (1 << i);
            }
        }
        if (b > 0) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}