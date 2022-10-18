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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        ll sum = 0, x = 0;

        for(int i = 0; i < n; i++){
            ll a; cin >> a;
            sum += a;
            x ^= a;
        }

        ll ans1 = 0, ans23 = 0;

        if(sum & 1){
            ans1 = 1;
            sum += 1;
            x ^= 1;
        }

        ans1 += (1LL << 50);
        sum += (1LL << 50);
        x ^= (1LL << 50);

        x <<= 1;
        //cerr << sum << " " << x << "\n";
        int i = 0;
        for(i = 0; i < 60 && (1LL << i) <= max(sum, x); i++){
            if(((1LL << i) & sum) == ((1LL << i) & x)) continue;
            //cerr << i << " " << sum << " " << x << "\n";
            ans23 += (1LL << (i - 1));
            sum += (1LL << i);
        }
        //cerr << sum << " " << x << "\n";
        assert(i < 60);

        cout << "3\n" << ans1 << " " << ans23 << " " << ans23 << "\n";

    }

    return 0;
}