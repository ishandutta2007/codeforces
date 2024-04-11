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

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        string s;
        cin >> s;
        vector<int> d(n);
        for(int i = 0; i < n; i++){
            d[i] = s[i] - '0';
        }

        int t = -1;
        int mn = 11;
        for(int i = n - 1; i >= 0; i--){
            if(mn < d[i]){
                t = d[i];
            }
            mn = min(mn, d[i]);
        }

        vector<int> ans(n);
        vector<int> t2;
        t2.reserve(n);
        for(int i = 0; i < n; i++){
            if(d[i] >= t && (t2.empty() || t2.back() <= d[i])){
                t2.pb(d[i]);
                ans[i] = 2;
            }
        }
        
        vector<int> t1;
        t1.reserve(n);
        bool tans = false;
        for(int i = 0; i < n; i++){
            if(ans[i] != 0) continue;
            ans[i] = 1;
            if(t1.size() && t1.back() > d[i]){
                tans = true;
                break;
            }
            t1.pb(d[i]);
        }
        for(int i : t2){
            if(t1.size() && t1.back() > i){
                tans = true;
                break;
            }
            t1.pb(i);
        }

        if(tans){
            cout << "-\n";
            continue;
        }

        for(int i = 0; i < n; i++){
            cout << ans[i];
        }
        cout << "\n";

    }

    return 0;
}