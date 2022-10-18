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

        int n;
        cin >> n;

        int mx;
        cin >> mx;
        vector<int> a(n);
        vector<pii> b;
        vector<bool> c(n + 1);
        a[0] = mx;
        c[mx] = true;
        for(int i = 1; i < n; i++){
            int q;
            cin >> q;

            if(q != mx) a[i] = q, mx = q, c[q] = true;
            else b.eb(mp(q, i));
        }
        //printv(a, cerr);
        //printv(c, cerr);

        lsort(b);

        bool ans = true;
        int now = 1;
        for(pii p : b){
            //cerr << p.F << " " << p.S << "\n";
            for(; now <= n; now++){
                //cerr << now << "\n";
                if(c[now]) continue;
                if(p.F <= now){
                    //cerr << p.F << " " << p.S << " " << now << "\n";
                    ans = false;
                    break;
                }
                a[p.S] = now;
                c[now] = true;
                break;
            }
            if(a[p.S] == 0 || !ans){
                ans = false;
                break;
            }
        }

        if(!ans) cout << "-1\n";
        else printv(a, cout);

    }

    return 0;
}