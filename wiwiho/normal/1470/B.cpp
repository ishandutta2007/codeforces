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
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

vector<int> prime;
vector<int> p;
void sieve(int n){
    prime.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            p.push_back(i);
            prime[i] = i;
        }
        for(int j : p){
            if((ll)i * j > n || j > prime[i]) break;
            prime[i * j] = j;
        }
    }
}

int main(){
    StarBurstStream

    sieve(1000000);
    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        map<vector<int>, int> cnt;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;

            vector<int> v;
//            cerr << a << "  ";

            while(a > 1){
                int t = prime[a];
                int c = 0;
                while(a % t == 0){
                    c++;
                    a /= t;
                }
                if(c % 2) v.eb(t);
            }
//            printv(v, cerr);

            cnt[v]++;
        }

        int ans0 = 0, ans1 = 0;
        for(auto& i : cnt){
            ans0 = max(ans0, i.S);
            if(i.S % 2 == 0 || i.F.empty()) ans1 += i.S;
        }

        int q;
        cin >> q;
        while(q--){
            ll w;
            cin >> w;
            if(w == 0) cout << ans0 << "\n";
            else cout << max(ans0, ans1) << "\n";
        }

    }

    return 0;
}