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

const int N = 2e5 + 10;
int n;

const int OPEN = 0;
const int CLOSE = 1;

struct Event {
    ll t;
    int type;
    int id;
    Event() = default;
    Event(ll _t, int _type, int _id) : t(_t), type(_type), id(_id) {}
    bool operator< (const Event& e) const {
        if (t != e.t)
            return t < e.t;
        if (type != e.type)
            return type < e.type;
        return id < e.id;
    }
};
using pli = pair<ll, int>;
ll t[N];
ll close[N];
set<pli> blacks;

int choose_black(ll start) {
    while(!blacks.empty()) {
        ll curt;
        int cid;
        tie(curt, cid) = *blacks.begin();
        if (start + curt <= close[cid]) {
            return cid;
        }
        blacks.erase(blacks.begin());
    }
    return -1;
}

void solve() {
    scanf("%d", &n);
    set<Event> evs;
    for(int i = 0; i < n; ++i) {
        ll a, b;
        scanf("%lld%lld%lld", &a, &b, &t[i]);
        close[i] = b;
        evs.emplace(a, OPEN, i);
        evs.emplace(b, CLOSE, i);
    }
    ll made = 0;
    ll start = 0;
    int id = -1;
    while(!evs.empty()) {
        auto deadline = evs.begin()->t;
        dbg(made, start, id, deadline);
        if (id == -1) {
            start = deadline;
        } else {
            auto curt = t[id];
            auto cnt = (deadline - start) / curt;
            made += cnt;
            start += cnt * curt;
        }
        ll next_sw = deadline;
        id = choose_black(start);
        dbg(id);
        if (id == -1) {
            auto ev = *evs.begin();
            evs.erase(evs.begin());
            if (ev.type == CLOSE) {
                blacks.erase(make_pair(t[ev.id], ev.id));
            } else {
                blacks.emplace(t[ev.id], ev.id);
                id = ev.id;
                start = deadline;
            }
            continue;
        }
        next_sw = start + t[id];
        while(!evs.empty()) {
            auto ev = *evs.begin();
            if (ev.t >= next_sw) {
                ++made;
                start = next_sw;
                id = choose_black(start);
                break;
            }
            evs.erase(evs.begin());
            if (ev.type == CLOSE) {
                blacks.erase(make_pair(t[ev.id], ev.id));
            } else {
                blacks.emplace(t[ev.id], ev.id);
                if (ev.t + t[ev.id] < next_sw) {
                    id = ev.id;
                    next_sw = ev.t + t[ev.id];
                }
            }
        }
    }
    printf("%lld\n", made);
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