//#define NDEBUG
 
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
 
const ll MOD = 1000000007;
const ll MAX = 2147483647;
 
int main(){
    StarBurstStream
 
    int n;
    cin >> n;

    if(n % 2 == 0) return cout << "NO\n", 0;

    vector<int> a, b;
    a.reserve(n); b.reserve(n);

    for(int i = 1; i <= n - 1; i++){

        if(i % 2){
            a.pb(i);
            a.pb(2 * n + 1 - i);
        }
        else{
            b.pb(i);
            b.pb(2 * n + 1 - i);
        }

    }

    cout << "YES\n";

    a.pb(n);
    b.pb(n + 1);
    
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
 
    return 0;
}