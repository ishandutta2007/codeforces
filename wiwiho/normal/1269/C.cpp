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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, k;
    string x;
    cin >> n >> k >> x;

    vector<int> ans(k);
    for(int i = 0; i < k; i++) ans[i] = x[i] - '0';

    bool t = true;
    for(int i = k; i < n; i++){
        if(x[i] - '0' < ans[i % k]) break;
        if(x[i] - '0' > ans[i % k]){
            t = false;
            //cerr << i << " " << ans[i % k] << "\n";
            break;
        }
    }

    if(!t)
        for(int i = k - 1; i >= 0; i--){
            if(ans[i] != 9){
                ans[i]++;
                for(int j = i + 1; j < k; j++) ans[j] = 0;
                break;
            }
        }

    cout << n << "\n";
    for(int i = 0; i < n; i++) cout << ans[i % k];
    cout << "\n";

    return 0;
}