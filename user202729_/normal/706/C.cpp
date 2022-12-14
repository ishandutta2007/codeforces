// Start: 7:30 AM.
// C. Hard problem
// http://codeforces.com/contest/706/problem/C

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

#define MAX 100000
const long long INF = std::numeric_limits<long long>::max();

int n, c[MAX];
long long dp0[MAX], dp1[MAX];
std::string stri_1, stri; // str[i-1] and str[i]
bool leq[4][MAX];
/* leq[i][MAX] = (i & 2) ? reverse(str[i-1]) : str[i-1] <
       (i & 1) ? reverse(str[i]) : i        (i>0)*/

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> c[i];
    std::cin >> stri_1;
    for (int i = 1; i < n; i++) {
        std::cin >> stri;
        leq[0][i] = stri_1 <= stri;
        std::reverse(stri.begin(), stri.end());
        leq[1][i] = stri_1 <= stri;
        std::reverse(stri_1.begin(), stri_1.end());
        leq[3][i] = stri_1 <= stri;
        std::reverse(stri.begin(), stri.end()); // may make a copy (still O(2*n))
        leq[2][i] = stri_1 <= stri;
        std::swap(stri_1, stri); // basically stri_1 = std::move(stri) but I don't know how to move
    }
    // now, fill dp.
    dp0[n-1] = 0LL;
    dp1[n-1] = c[n-1];
    for (int i = n-2; i >= 0; i--) {
        dp0[i] = dp1[i] = INF;
        if (dp0[i+1] != INF) {
            if (leq[0][i+1]) dp0[i] = std::min(dp0[i], dp0[i+1]);
            if (leq[2][i+1]) dp1[i] = std::min(dp1[i], dp0[i+1] + c[i]);
        }
        if (dp1[i+1] != INF) {
            if (leq[1][i+1]) dp0[i] = std::min(dp0[i], dp1[i+1]);
            if (leq[3][i+1]) dp1[i] = std::min(dp1[i], dp1[i+1] + c[i]);
        }
    }
    long long result = std::min(dp0[0], dp1[0]);
    if (result != INF) std::cout << result; else std::cout << "-1";
    std::cout << "\n";
}