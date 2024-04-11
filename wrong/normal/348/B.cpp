#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const Int INFL = 10010010010010LL;
const int MAXV = 100050, MAXE = 200050;
int ptr[MAXV], next[MAXE], adj[MAXE];
int weight[MAXV];

int N;

struct ans {
    Int apples, sub;
    ans() { }
    ans(Int a, Int s) : apples(a), sub(s) { }
} A[100050];

Int gcd(Int m, Int n)
{
    return n ? gcd(n, m % n) : m;
}

Int safe_lcm(Int m, Int n)
{
    if (m == INFL || n == INFL) return INFL;
    Int lcm = m / gcd(m, n);
    if (lcm > INFL / n + 10) return INFL;
    lcm *= n;
    return min(lcm, INFL);
}

ans dfs(int u, int p = -1)
{
    Int sub = 1;
    for (int z = ptr[u]; ~z; z = next[z]) {
        int v = adj[z];
        if (v != p) {
            // cerr<<u<<"->"<<v<<endl;
            dfs(v, u);
            sub = safe_lcm(sub, A[v].sub);
        }
    }

    Int apples_min = INFL;
    int num_child = 0;
    for (int z = ptr[u]; ~z; z = next[z]) {
        int v = adj[z];
        if (v != p) {
            chmin(apples_min, A[v].apples / sub * sub);
            num_child++;
        }
    }
    if (num_child == 0) {
        return A[u] = ans(weight[u], 1);
    }
// cerr<<u<<' '<<apples_min<<' '<<sub<< ' '<<num_child<<endl;
    return A[u] = ans(apples_min * num_child, sub * num_child);
}

int main()
{
    Int tot = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &weight[i]);
        tot += weight[i];
    }

    memset(ptr, ~0, sizeof(ptr));
    for (int i = 0, e = 0; i < N - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        next[e] = ptr[x]; ptr[x] = e; adj[e] = y; ++e;
        next[e] = ptr[y]; ptr[y] = e; adj[e] = x; ++e;
    }

    cout << tot - dfs(0).apples << endl;

    return 0;
}