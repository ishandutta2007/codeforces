//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<string> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<pii> tmp = {mp(0, 1), mp(1, 0), mp(n - 1, n - 2), mp(n - 2, n - 1)};
        vector<bool> ans(4);
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            if(i <= 1 && a[tmp[i].F][tmp[i].S] != '1'){
                ans[i] = true;
                cnt++;
            }
            else if(i > 1 && a[tmp[i].F][tmp[i].S] != '0'){
                ans[i] = true;
                cnt++;
            }
        }
        if(cnt > 2){
            for(int i = 0; i < 4; i++) ans[i] = !ans[i];
            cnt = 4 - cnt;
        }

        cout << cnt << "\n";
        for(int i = 0; i < 4; i++){
            if(ans[i]) cout << tmp[i].F + 1 << " " << tmp[i].S + 1 << "\n";
        }

    }

    return 0;
}