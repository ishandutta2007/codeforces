#include <bits/stdc++.h>
#define getchar gtx
#define int long long
using namespace std;

const int maxn = 1e7 + 10;
int a[maxn], mdiv[maxn], pw[maxn], s[maxn];
bool v[maxn], need[maxn];
vector<int> pr;

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
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) mdiv[i] = pr.size(), pr.push_back(i);
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            mdiv[i * pr[j]] = j;
            if (i % pr[j] == 0) break;
        }
    }
}

bool check(int to, int p) {
    int got = 0;
    int now = 1;
    for (int i = 0; ; ++i) {
        got += to / now;
        if (to / now == 0) break;
        now *= pr[p];
    }
    return got >= pw[p];
}

int32_t main() {
    sieve();
    // cout << "bang" << endl;
    int n; rit(n);
    for (int i = 0; i < n; ++i) {
        rit(a[i]);
        ++s[1]; --s[a[i] + 1];
    }
    int now = 0;
    for (int i = 1; i < maxn; ++i) {
        now += s[i];
        if (now == 0) continue;
        int know = i;
        while (know > 1) {
            int d = mdiv[know];
            int c = 0;
            while (know % pr[d] == 0) know /= pr[d], ++c;
            need[d] = true;
            pw[d] += c * now;
        }
    }
    int k = 1;
    // sort(need.begin(), need.end()); need.resize(unique(need.begin(), need.end()) - need.begin());
    // cout << "bang" << endl;
    long long ans = 0;
    for (int i = 0; i < pr.size(); ++i) if (need[i]) {
        // cout << "i = " << i << " pw = " << pw[i] << endl;
        int d = 60, p = (1ll << 60); 
        while (d--) if (p - (1ll << d) >= 0) if (check(p - (1ll << d), i)) p -= (1ll << d);
        // cout << "p = " << p << endl;
        ans = max(ans, p * pr[i]);
    }
    ans = max(ans, 1ll);
    printf("%I64d\n", ans);
}