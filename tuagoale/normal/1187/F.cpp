/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
 */

#define OK printf ("Pass on Line #%d\n", __LINE__)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void write(T *st, int n, string s = "") {
    if (s.size()) cout << s << ": ";
    while (n--) write(*st++, ' ');
    puts("");
}

const int N = 200050;
const int P = 1e9 + 7;
ll len[N], p[N], sum[N], ans;
int L[N], R[N], n;
ll fpw(ll x, ll mi, ll res = 1) { for (; mi; mi >>= 1, x = x * x % P) if (mi & 1) res = res * x % P; return res; }
int main() {
    read(n);
    for (int i = 1;i <= n; ++i) read(L[i]);
    for (int i = 1;i <= n; ++i) read(R[i]), len[i] = R[i] - L[i] + 1;
    ll ans = p[0] = 1; len[0] = 1; sum[0] = 1;
    for (int i = 1;i < n; ++i) {
        p[i] = max(0, min(R[i], R[i + 1]) - max(L[i], L[i + 1]) + 1);
        p[i] = p[i] * fpw(len[i] * len[i + 1] % P, P - 2) % P, p[i] = (P + 1 - p[i]) % P;
        ans = (ans + p[i] + (i > 1 ? 2 * p[i] * sum[i - 2] : 0)) % P, sum[i] = (sum[i - 1] + p[i]) % P;
        int tr = min(min(R[i], R[i + 1]), R[i - 1]), tl = max(max(L[i], L[i + 1]), L[i - 1]);
        int t = max(tr - tl + 1, 0) * fpw(len[i - 1] * len[i] % P * len[i + 1] % P, P - 2) % P;
        /* write(tr - tl + 1, ' '); */
        /* write(t, ' '); */
        t = (1ll - (1 - p[i - 1] + 1 - p[i]) + t) % P;
        /* write(t); */
        ans = (ans + 2 * t) % P;
        /* write(p[i]); */
    }
    write((ans % P + P) % P);
    return 0;
}