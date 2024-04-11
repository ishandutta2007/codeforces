//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    BIT.resize(n + m + 1);
    vector<int> pos(n + 1);
    vector<pii> ans(n + 1);
    for(int i = 1; i <= n; i++){
        pos[i] = n - i + 1;
        modify(i, 1);
        ans[i] = mp(i, i);
    }

    for(int i = n + 1; i <= n + m; i++){
        int a;
        cin >> a;

        int p = pos[a];
        ans[a].S = max(ans[a].S, query(n + m) - query(p) + 1);
        ans[a].F = 1;
        modify(p, -1);
        modify(i, 1);
        pos[a] = i;
    }

    for(int i = 1; i <= n; i++){
        ans[i].S = max(ans[i].S, query(n + m) - query(pos[i]) + 1);
    }

    for(int i = 1; i <= n; i++) cout << ans[i].F << " " << ans[i].S << "\n";

    return 0;
}