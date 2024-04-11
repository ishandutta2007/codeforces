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


int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> m(n);
    for(int i =0 ;i < n; i++) cin >> m[i];

    ll ans = 0;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll now = 0;
        ll lst = MAX;
        vector<ll> tmp(n);
        for(int j = i; j >= 0; j--){
            lst = min(lst, m[j]);
            tmp[j] = lst;
            now += lst;
        }
        lst = tmp[i];
        for(int j = i + 1; j < n; j++){
            lst = min(lst, m[j]);
            tmp[j] = lst;
            now += lst;
        }

        if(now > ans){
            ans = now;
            v = tmp;
        }
    }

    printv(v, cout);

    return 0;
}