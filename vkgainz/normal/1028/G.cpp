#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <numeric>

using namespace std;

long long M = 1e16 + 1e12 * 1LL * 4 + 1e11 * 1LL * 2 + 1e9 * 1LL * 5
+ 361450474;
long long dp[10001][6];
long long r[6];

int query(int x, vector<long long> nums) {
    cout << x << " ";
    for (long long y : nums) cout << y << " ";
    cout << "\n";
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

long long get(long long x, int left) {
    if (x > 10000) {
        return r[left] + x - 1;
    } 
    if (dp[x][left] != 0) return dp[x][left];
    if (left == 1) {
        dp[x][left] = x * 2 - 1;
        return dp[x][left];
    } else {
        long long curr = x;
        for (int i = 1; i <= x; i++) {
            curr = get(curr, left - 1) + 2;
        }
        curr = get(curr, left - 1);
        dp[x][left] = curr;
        return curr;
    }
}

void solve(long long lo, long long hi, int left) {
    vector<long long> qry;
    if (left == 1) {
        for (long long i = lo; i <= hi; i++) {
            qry.push_back(i);
        }
    } else {
        long long curr = lo;
        for (int i = 1; i <= min(lo, 1LL * 10000); i++) {
            long long nxt = get(curr, left - 1);
            if (nxt > hi) break;
            qry.push_back(nxt + 1);
            curr = nxt + 2;
        }
    }
    int nxt = query(qry.size(), qry);
    if (nxt == -1) return;
    if (nxt == 0) {
        hi = qry[nxt] - 1;
    } else if (nxt == qry.size()) {
        lo = qry[nxt - 1] + 1;
    } else {
        lo = qry[nxt - 1] + 1;
        hi = qry[nxt] - 1;
    }
    solve(lo, hi, left - 1);
}

int main() {
    long long lo = 1LL, hi = M;
    r[1] = 10000;
    for (int i = 2; i <= 4; i++) 
        r[i] = r[i - 1] * 10001 + 10000;
    solve(lo, hi, 5);
}