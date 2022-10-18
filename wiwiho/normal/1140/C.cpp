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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<pll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].S >> a[i].F;

    gsort(a);
    ll sum = 0;
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for(int i = 0; i < n; i++){
        if(pq.size() >= k && pq.top() < a[i].S){
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() < k){
            pq.push(a[i].S);
            sum += a[i].S;
        }
        ans = max(ans, sum * a[i].F);
    }

    cout << ans << "\n";

    return 0;
}