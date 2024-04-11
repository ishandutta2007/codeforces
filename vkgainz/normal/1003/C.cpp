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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ans = 0.0;
    for (int i = 0; i < n ;i++) {
        for (int j = i; j < n ;j++) {
            if (i == j) sm[i][j] = a[i];
            else sm[i][j] = a[j] + sm[i][j - 1];
            if (j -i + 1 >= k) {
                ans = max(ans, sm[i][j] * 1.0 / (j - i + 1));
            }
        }
    }
    cout << setprecision(24);
    cout << ans << "\n";
}