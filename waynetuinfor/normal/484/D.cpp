#include <bits/stdc++.h>
using namespace std;
inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }
const int maxn = 1e6 + 10;
int a[maxn];
long long dp[maxn];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n; rit(n);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        // for (int j = 0; j < min(3, ()))
        for (int j = vec.size() - 1, cnt = 0; j >= 0 && cnt < 7; --j, ++cnt) {
            for (int k = -5; k <= 60; ++k) {
                if (vec[j] + k >= 0 && vec[j] + k < i) dp[i] = max(dp[i], dp[vec[j] + k] + abs(a[i] - a[vec[j] + k + 1]));
            }
        }
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) vec.push_back(i);
        else if (a[i] < a[i - 1] && a[i] < a[i + 1]) vec.push_back(i);
        else if (i <= 10) vec.push_back(i);
    }   
    cout << dp[n] << endl;
    return 0;
}