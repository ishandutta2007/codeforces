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

    int n;
    cin >> n;

    sieve(200000);

    vector<vector<int>> cnt(p.size());

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        while(a > 1){
            int c = 0, t = prime[a];
//            cerr << a << " " << t << "\n";
            while(a % t == 0){
                c++;
                a /= t;
//                cerr << "test " << a << " " << t << "\n";
            }
            cnt[lower_bound(iter(p), t) - p.begin()].eb(c);
        }
    }

    ll ans = 1;
    for(int i = 0; i < p.size(); i++){
        lsort(cnt[i]);
        int c;
        if(cnt[i].size() == n) c = cnt[i][1];
        else if(cnt[i].size() == n - 1) c = cnt[i][0];
        else c = 0;
        while(c--) ans *= p[i];
    }

    cout << ans << "\n";

    return 0;
}