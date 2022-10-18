//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

bool comp(pii a, pii b){
    return a.F > b.F ? true : a.F == b.F && a.S < b.S;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].F;
        b[i] = a[i].F;
        a[i].S = i;
    }

    sort(iter(a), comp);

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
            t;

    int m;
    cin >> m;
    vector<pair<pii, int>> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i].F.F >> q[i].F.S;
        q[i].S = i;
    }

    vector<int> ans(m);
    lsort(q);

    for(int i = 0; i < m; i++){
        while(t.size() < q[i].F.F){
            t.insert(a[t.size()].S);
        }
        ans[q[i].S] = *t.find_by_order(q[i].F.S - 1);
    }
    for(int i = 0; i < m; i++) cout << b[ans[i]] << "\n";

    return 0;
}