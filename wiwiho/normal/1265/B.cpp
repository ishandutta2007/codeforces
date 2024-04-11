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
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n ;
        cin >> n;

        vector<int> p(n);
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i] == 1) l = i, r = i;
        }

        string ans(n, '0');
        ans[0] = '1';
        int mx = 1;
        int cnt = 1;
        while(l > 0 || r < n - 1){
            //cerr << l << " " << r << "\n";

            if(l == 0 || (r < n - 1 && p[l - 1] > p[r + 1])){
                r++;
                mx = max(mx, p[r]);
                cnt++;
            }
            else if(r == n - 1 || (l > 0 && p[l - 1] < p[r + 1])){
                l--;
                mx = max(mx, p[l]);
                cnt++;
            }

            if(mx == cnt) ans[mx - 1] = '1';

        }

        cout << ans << "\n";

    }

    return 0;
}