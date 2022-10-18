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

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cnt(201);
        for(int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

        int ans = 1;

        for(int i = 1; i <= 200; i++){
            if(cnt[i] >= 2) ans = 2;
        }

        vector<int> l(201);
        for(int i = 0; i < n - 2; i++){

            multiset<int, greater<>> slr, sm;
            vector<int> r(201), m(201);

            l[a[i]]++;
            for(int j = i + 1; j < n; j++) m[a[j]]++;
            for(int j = 1; j <= 200; j++) slr.insert(min(l[j], r[j])), sm.insert(m[j]);

            for(int j = n - 1; j - i >= 2; j--){
                slr.erase(slr.find(min(l[a[j]], r[a[j]])));
                sm.erase(sm.find(m[a[j]]));
                m[a[j]]--;
                r[a[j]]++;
                slr.insert(min(l[a[j]], r[a[j]]));
                sm.insert(m[a[j]]);
                ans = max(ans, *slr.begin() * 2 + *sm.begin());
            }

        }

        cout << ans << "\n";

    }

    return 0;
}