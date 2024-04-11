#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 2147483647;

vector<bool> prime(1011, true);
vector<int> primev;


int main(){
    StarBurstStream

    int n;
    cin >> n;

    for(int i = 2; i < 1011; i++){
        if(!prime[i]) continue;
        primev.pb(i);
        for(int j = i; j * i < 1011; j++){
            prime[j * i] = false;
        }
    }

    int m = *lower_bound(primev.begin(), primev.end(), n);

    cout << m << "\n";

    for(int i = 1; i < n; i++){
        cout << i << " " << i + 1 << "\n";
    }
    cout << 1 << " " << n << "\n";

    for(int i = 1; i <= m - n; i++){
        cout << i << " " << n / 2 + i << "\n";
    }

    return 0;

}