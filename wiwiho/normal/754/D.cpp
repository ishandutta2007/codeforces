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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<pii > c;
set<int> ans;
ll n, k;

vector<pair<int, pii>> e;

bool check(int len, bool t){
//    cerr << "test " << len << "\n";
    if(len == 0) return true;
    e.clear();
    for(int i = 0; i < n; i++){
        if(c[i].S - c[i].F + 1 < len) continue;
        e.eb(mp(c[i].F, mp(1, i)));
        e.eb(mp(c[i].S - len + 2, mp(0, i)));
    }
    lsort(e);

    set<int> now;
    int cnt = 0;
    for(auto &i : e){
//        cerr << i << "\n";
        if(i.S.F == 1){
            if(t) now.insert(i.S.S);
            cnt++;
        }
        else{
            if(t) now.erase(i.S.S);
            cnt--;
        }
        if(cnt >= k){
            if(t) ans = now;
            return true;
        }
    }
    return false;
}

int main(){
    StarBurstStream

    cin >> n >> k;

    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i].F >> c[i].S;
//    printv(c, cerr);

    ll l = 0, r = 2000000001;

    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(check(mid, false)) l = mid;
        else r = mid - 1;
    }

    if(l == 0){
        cout << "0\n";
        for(int i = 1; i <= k; i++) cout << i << " ";
        cout << "\n";
        return 0;
    }

    check(l, true);

    cout << l << "\n";
    int cnt = 0;
    for(int i : ans){
        cout << i + 1 << " ";
        cnt++;
        if(cnt == k) break;
    }
    cout << "\n";

    return 0;
}