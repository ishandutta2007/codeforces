//#define NDEBUG

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = (1LL << 60);

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> p(2750132, 1);
    vector<int> primes;
    for(int i = 2; i <= 2750131; i++){
        if(p[i] == 1){
            primes.eb(i);
            p[i] = i;
        }
        for(int j : primes){
            if((ll)j * i > 2750131) break;
            p[j * i] = j;
            if(j == p[i]) break;
        }
    }

    map<int, int, greater<>> b;
    for(int i = 0; i < 2 * n ;i++){
        int t;
        cin >> t;
        b[t]++;
    }

    vector<int> a;
    for(auto& i : b) while(i.S > 0){
        if(p[i.F] == i.F){
            int t = lower_bound(iter(primes), i.F) - primes.begin() + 1;
            a.eb(t);
            b[t]--;
            i.S--;
            //cerr << "test1 " << i.F << " " << t << "\n";
        }
        else{
            int t = i.F / p[i.F];
            a.eb(i.F);
            b[t]--;
            i.S--;
            //cerr << "test2 " << i.F << " " << t << "\n";
        }
    }

    printv(a, cout);

    return 0;
}