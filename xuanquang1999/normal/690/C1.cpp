// Created by hoangvanthien

#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;
int n, m;
vector<int> dsk[N];
int d[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    if (m != n - 1) {
        puts("no");
        return 0;
    }
    FOR(i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    queue<int> q;
    q.push(1);
    d[1] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        forit(it, dsk[u]) if (!d[*it]) {
                d[*it] = true;
                q.push(*it);
            }
    }
    FOR(i, 1, n) if (!d[i]) {
            puts("no");
            return 0;
        }
    puts("yes");


}