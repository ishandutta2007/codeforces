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
 
    int q;
    cin >> q;
 
    while(q--){
 
        int n;
        cin >> n;
 
        map<int, int> cnt;
        for(int i = 0; i < 4 * n; i++){
            int t;
            cin >> t;
            cnt[t]++;
        }
        vector<int> a;
        a.reserve(2 * n);
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            it->second /= 2;
            for(int i = 0; i < it->second; i++) a.pb(it->first);
        }
 
        if(a.size() != 2 * n){
            cout << "NO\n";
            continue;
        }
 
        bool ans = true;
        int t = a[0] * a[a.size() - 1];
        for(int i = 1, j = a.size() - 2; i < j; i++, j--){
            if(a[i] * a[j] != t){
                ans = false;
                break;
            }
        }
        printv(a, cerr);
 
        cout << (ans ? "YES\n" : "NO\n");
 
    }
 
    return 0;
}