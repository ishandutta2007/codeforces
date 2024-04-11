#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <random>

using namespace std;

#define ll long long
mt19937 RND((uint64_t) new char);

inline ll read () {
    ll ret = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') ret = (ret << 1) + c - '0', c = getchar();
    return ret;
}
const int MAXN = 200200;
ll val[MAXN];

int buc[MAXN], n, m, p;
void FWT (int N) {
    for (int i = 2; i <= N; i <<= 1)
        for (int j = 0; j < N; j += i) 
            for (int k = j; k < j + (i >> 1); k++)
                buc[k] += buc[k + (i >> 1)];
}

void binout (int x) { printf("%d%d%d%d\n", (x >> 3) & 1, (x >> 2) & 1, (x >> 1) & 1, x & 1); }

int main () {
    scanf("%d%d%d", &n, &m, &p);
    int i, j, T = 10;
    for (i = 1; i <= n; i++) val[i] = read();
    ll ans = 0, out = 0;
    while (T--) {
        vector <int> bits; int id = RND() % n + 1; // cout << id << endl;
        for (i = 0; i < m; i++) if ((val[id] >> i) & 1) bits.push_back(i); //, cout << i << ' ';
        // cout << endl;
        for (i = 0; i < (1 << p); i++) buc[i] = 0;
        for (i = 1; i <= n; i++) {
            int now = 0;
            for (j = 0; j < bits.size(); j++) if ((val[i] >> bits[j]) & 1) now += 1 << j;
            ++buc[now];
        }
        // printf("%d %d %d %d\n", buc[0], buc[1], buc[2], buc[3]);
        FWT(1 << bits.size());
        // printf("%d %d %d %d\n", buc[0], buc[1], buc[2], buc[3]);
        for (i = 0; i < (1 << p); i++) if (buc[i] >= ((n + 1) >> 1) && __builtin_popcount(i) > ans) {
            ans = __builtin_popcount(i); out = 0;
            for (j = 0; j < bits.size(); j++) if ((i >> j) & 1) out += 1ll << bits[j];
        }
        // cout << out << endl;
    }
    for (i = m - 1; i >= 0; i--) printf("%d", (out >> i) & 1);
    return 0;
}