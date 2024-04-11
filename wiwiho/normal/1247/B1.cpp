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

    int t;
    cin >> t;

    while(t--){

        int n, k, d;
        cin >> n >> k >> d;

        vector<int> a(n);

        map<int, int> cnt;

        int ans = MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;

            if(i - d >= 0){
                cnt[a[i - d]]--;
                if(cnt[a[i - d]] == 0) cnt.erase(a[i - d]);
            }
            if(i + 1 >= d){
                ans = min(ans, (int)cnt.size());
            }
        }
        cout << ans << "\n";

    }

    return 0;
}