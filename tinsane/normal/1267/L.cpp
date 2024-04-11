#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<functional>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int N = 1010;
const int B = N * N;
int n, l, k;
char buf[B];
const int A = 'z' - 'a' + 1;
int cnt[A];
vector<string> res;
int bptr = A - 1;
int gptr = 0;

void fill_bad(int id) {
    while((int)res[id].size() < l) {
        while (cnt[bptr] == 0) {
            --bptr;
        }
        res[id].push_back('a' + bptr);
        --cnt[bptr];
    }
}

void solve(int lb, int rb) {
    dbg(lb, rb, res[k]);
    if ((int)res[k].size() == l)
        return;
    while (rb - lb + 1 <= cnt[gptr]) {
        for(int i = lb; i <= rb; ++i)
            res[i].push_back('a' + gptr);
        cnt[gptr] -= rb - lb + 1;
    }
    int mid = lb;
    while(cnt[gptr] > 0) {
        res[mid].push_back('a' + gptr);
        ++mid;
        --cnt[gptr];
    }
    ++gptr;
    for(int i = mid - 1; i >= lb; --i)
        fill_bad(i);
    solve(mid, rb);
}

void solve() {
    scanf("%d%d%d", &n, &l, &k);
    --k;
    scanf("%s", buf);
    for(int i = 0; i < n * l; ++i)
        ++cnt[buf[i] - 'a'];
    res.resize(n);
    for(int i = n - 1; i > k; --i) {
        fill_bad(i);
    }
    solve(0, k);
    for(int i = 0; i < n; ++i)
        puts(res[i].c_str());
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
    return 0;
}