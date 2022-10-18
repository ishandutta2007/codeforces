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

    int last = -1;
    int cnt = 0;
    int oddsum = 0;
    int evensum = 0;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > 0) continue;

        cnt++;
        if(cnt % 2 == 1){
            ans += (ll)evensum * (i - last);
            //cerr << cnt << " " << evensum << " " << (i - last) << " " << (ll)evensum * (i - last) << "\n";
            oddsum += i - last;
        }
        else{
            ans += (ll)oddsum * (i - last);
            //cerr << cnt << " " << oddsum << " " << (i - last) << " " << (ll)oddsum * (i - last) << "\n";
            evensum += i - last;
        }
        last = i;

    }
    cnt++;
    if(cnt % 2 == 1){
        ans += (ll)evensum * (n - last);
    }
    else{
        ans += (ll)oddsum * (n - last);
    }

    ll all = (ll)(1 + n) * n / 2;
    cout << ans << " " << (all - ans) << "\n";


    return 0;
}