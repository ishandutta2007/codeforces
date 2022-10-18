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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

        int n, m;
        cin >> n >> m;

        vector<ll> a(m + 1), b(m + 1);
        for(int i = 1; i <= m; i++) cin >> a[i] >> b[i];

        vector<ll> p = a;
        sort(p.begin() + 1, p.end(), greater<>());
        vector<ll> sum = p;
        for(int i = 1; i <= m; i++){
            sum[i] += sum[i - 1];
        }
//        printv(p, cerr);
//        printv(sum, cerr);
//        printv(a, cerr);
//        printv(b, cerr);

        ll ans = 0;
        for(int i = 1; i <= m; i++){
            ll now = b[i];
            int t = upper_bound(p.begin() + 1, p.end(), now, greater<>()) - p.begin() - 1;
            t = min(t, n);
            ll tans = 0;
//            cerr << t << "\n";
            if(t == 0){
                tans = a[i] + (n - 1) * b[i];
            }
            else if(a[i] < p[t]){
                if(t == n){
                    t--;
                    tans = sum[t];
                    t++;
                    tans += a[i] + (n - t) * b[i];
                }
                else{
                    tans = sum[t];
                    t++;
                    tans += a[i] + (n - t) * b[i];
                }
            }
            else{
                tans = sum[t];
                tans += (n - t) * b[i];
            }
            ans = max(ans, tans);
        }
        cout << ans << "\n";

    }

    return 0;
}