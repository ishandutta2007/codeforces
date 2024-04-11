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

    int q;
    cin >> q;

    while(q--){

        int n;
        cin >> n;

        vector<ll> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i] /= 100;
        }
        gsort(p);
        vector<ll> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + p[i - 1];

        ll x, a;
        cin >> x >> a;
        ll y, b;
        cin >> y >> b;

        if(x < y){
            swap(x, y);
            swap(a, b);
        }
        ll k;
        cin >> k;

        vector<ll> t = {x, y, x + y};
        vector<int> cnt(3);
        for(int i = 1; i <= n; i++){

            if(i % a == 0 && i % b == 0) cnt[2]++;
            else if(i % a == 0) cnt[0]++;
            else if(i % b == 0) cnt[1]++;

            ll money = (s[cnt[2]] - s[0]) * t[2] + (s[cnt[2] + cnt[0]] - s[cnt[2]]) * t[0] + (s[cnt[2] + cnt[0] + cnt[1]] - s[cnt[2] + cnt[0]]) * t[1];
            if(money >= k){
                cout << i << "\n";
                goto next;
            }

        }
        cout << "-1\n";

        next:;
    }

    return 0;
}