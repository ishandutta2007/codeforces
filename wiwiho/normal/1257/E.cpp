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

int main(){
    StarBurstStream

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    int n = k1+ k2 + k3;
    vector<int> a1(n), a2(n), a3(n);

    for(int i = 0; i < k1; i++){
        int t;
        cin >> t;
        a1[t - 1] = 1;
    }
    for(int i = 0; i < k2; i++){
        int t;
        cin >> t;
        a2[t - 1] = 1;
    }
    for(int i = 0; i < k3; i++){
        int t;
        cin >> t;
        a3[t - 1] = 1;
    }

    for(int i = 1; i < n; i++){
        a1[i] += a1[i - 1];
        a2[i] += a2[i - 1];
        a3[i] += a3[i - 1];
    }

//    printv(a1, cerr);
//    printv(a2, cerr);
//    printv(a3, cerr);

    vector<int> pos(n);
    for(int i = 1; i < n; i++){
        if(a2[i] - a1[i] < a2[pos[i - 1]] - a1[pos[i - 1]]) pos[i] = i;
        else pos[i] = pos[i - 1];
    }
//    printv(pos, cerr);

    int ans = n - a3[n - 1];
    for(int i = 0; i < n; i++){
        ans = min(ans, a2[pos[i]] - a1[pos[i]] + a1[n - 1] + a3[i] + a2[n - 1] - a2[i]);
        ans = min(ans, a1[n - 1] + a3[i] + a2[n - 1] - a2[i]);
//        cerr << ans << "\n";
    }
    cout << ans << "\n";

    return 0;
}