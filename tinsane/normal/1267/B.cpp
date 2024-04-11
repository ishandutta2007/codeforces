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

const int N = 3e5 + 10;
int n;
char s[N];

bool check(int l) {
    int r = l;
    while(s[r] == s[l])
        ++r;
    --l;
    while(l >= 0) {
        dbg(l, r, s[l], s[r]);
        int cnt = 0;
        auto cur = s[l];
        while(l >= 0 && s[l] == cur) {
            ++cnt;
            --l;
        }
        if (s[r] != cur)
            return false;
        while(r < n && s[r] == cur) {
            ++cnt;
            ++r;
        }
        if (cnt < 3)
            return false;
    }
    return true;
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    int ccnt = 1;
    for(int i = 1; i < n; ++i)
        if (s[i] != s[i - 1])
            ++ccnt;
    if (ccnt % 2 == 0) {
        puts("0");
        dbg("ccnt");
        return;
    }
    if (ccnt == 1) {
        if (n < 2)
            puts("0");
        else
            printf("%d\n", n + 1);
        return;
    }
    int cur = 1;
    int beg = 1;
    for(; beg < n; ++beg) {
        if (s[beg] != s[beg - 1])
            ++cur;
        if (cur * 2 - 1 == ccnt) {
            break;
        }
    }
    dbg(beg);
    int bcnt = 0;
    while(s[beg + bcnt] == s[beg])
        ++bcnt;
    dbg(bcnt);
    if (bcnt > 1 && check(beg))
        printf("%d", bcnt + 1);
    else
        puts("0");
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