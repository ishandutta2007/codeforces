#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

#define int long long

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
int a[500500];
int b[500500];

struct rua { int len, v; };

stack <rua> st;

int l[500500];
int r[600600];
signed main () {
    int n = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    st.push({1, a[1]}); int s =a[1]; l[1] = a[1];
    for (i = 2; i <= n; i++) {
        int tmp = 1;
        while (!st.empty() && st.top().v > a[i]) tmp += st.top().len, s -= st.top().v * st.top().len, st.pop();
        st.push({tmp, a[i]});
        s += a[i] * tmp;
        l[i] = s;
    }
    while (!st.empty()) st.pop();
    st.push({1, a[n]}); s = a[n]; r[n] = a[n];
    for (i = n - 1; i >= 1; i--) {
        int tmp = 1;
        while (!st.empty() && st.top().v > a[i]) tmp += st.top().len, s -= st.top().v * st.top().len, st.pop();
        st.push({tmp, a[i]});
        s += a[i] * tmp;
        r[i] = s;
    }
    int ans = 0, pos;
    for (i = 1; i <= n; i++) {
        if (ans < l[i] + r[i] - a[i]) ans = l[i] + r[i] - a[i], pos = i;
    }
    int Min = a[pos]; b[pos] = a[pos];
    for (i = pos - 1; i >= 1; i--) Min = min(Min, a[i]), b[i] = Min; Min = a[pos];
    for (i = pos + 1; i <= n; i++) Min = min(Min, a[i]), b[i] = Min;
    for (i = 1; i <= n; i++) printf("%lld ", b[i]);
    return 0;
}