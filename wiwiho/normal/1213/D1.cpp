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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] >= k){
            cout << "0\n";
            return 0;
        }
    }
    lsort(a);

    ll ans = MAX;
    for(int i = 0; i <= 200000; i++){
        
        vector<ll> temp;
        for(int j = 0; j < n; j++){
            int t = a[j];
            ll tt = 0;
            while(t > i){
                t /= 2;
                tt++;
            }
            if(t == i){
                temp.pb(tt);
            }
        }
        if(temp.size() < k) continue;
        ll tans = 0;
        lsort(temp);
        for(int i = 0; i < k; i++) tans += temp[i];
        ans = min(ans, tans);

    }

    cout << ans << "\n";

    return 0;
}