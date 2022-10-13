#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define all(c) ((c).begin()), ((c).end())

long long choose[51][51];

long long comp(vector<int> left, int len) {
    long long dp[len + 1][17];
    dp[0][0] = 1LL;
    for (int i = 1; i <= 16; i++) {
        dp[0][i] = 1LL;
    }
    for (int l = 1; l <= len; l++) {
        dp[l][0] = 0LL;
        for (int j = 1; j <= 16; j++) {
            dp[l][j] = 0LL;
            for (int put = 0; put <= min(left[j - 1], l); put++) {
                dp[l][j] += choose[l][put] * 1LL * dp[l - put][j - 1];
            }
        }
    }
    return dp[len][16];
}

int main() {
    int k, t; cin >> k >> t;
    int len = 0;
    for (int i = 0; i <= 50; i++) {
        choose[0][i] = 0;
        choose[i][0] = 1;
    }
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }
    while (true) {
        ++len;
        vector<int> tmp(16, t);
        long long r = 0LL;
        for (int f = 1; f < 16; f++) {
            tmp[f]--;
            r += comp(tmp, len - 1);
            tmp[f]++;
        }
        if (r >= k) {
            break;
        } else {
            k -= r;
        }
    }
    vector<int> put(len, -1);
    vector<int> left(16, t);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 16; j++) {
            if (left[j] >= 1 && (j >= 1 || (j == 0 && i > 0))) {
                --left[j];
                long long add = comp(left, len - i - 1);
                if (add < k) {
                    k -= add;
                    ++left[j];
                } else {
                    if (put[i] == -1)
                        put[i] = j;
                    break;
                }
            }
        }
    }
    string ref = "0123456789abcdef";
    for (int i = 0; i < len; i++) {
        cout << ref[put[i]];
    }
    cout << "\n";
}