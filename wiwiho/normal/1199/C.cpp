#define NDEBUG

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
const ll MAX = 1000000000;

using namespace std;

int main(){
    StarBurstStream

    int n, I;
    cin >> n >> I;

    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        cnt[t]++;
    }

    vector<int> t;
    t.reserve(cnt.size());
    for(pii p : cnt) t.pb(p.S);

    int k = (1 << min(I * 8 / n, 25));
    if(k > t.size()){
        cout << "0\n";
        return 0;
    }
    //printv(t, cerr);

    int l = 0;
    int r = k - 1;
    int sum = 0;
    for(int i = l; i <= r; i++){
        sum += t[i];
    }
    int ans = n - sum;
    while(r + 1 < t.size()){
        sum -= t[l];
        l++;
        r++;
        sum += t[r];
        //cerr << l << " " << r << " " << sum << "\n";
        ans = min(n - sum, ans);
    }

    cout << ans << "\n";

    return 0;
}