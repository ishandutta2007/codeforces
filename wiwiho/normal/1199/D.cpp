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

    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].F;

    int q;
    cin >> q;

    vector<int> p(q, -1);

    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int y, x;
            cin >> y >> x;
            y--;
            a[y].F = x;
            a[y].S = i;
        }
        else{
            cin >> p[i];
        }
    }

    int mx = -1;
    for(int i = q - 1; i >= 0; i--){
        if(p[i] != -1 && (mx == -1 || p[i] > mx)){
            mx = p[i];
        }
        p[i] = mx;
    }

    for(int i = 0; i < n; i++){
        if(p[a[i].S] != -1){
            cout << max(a[i].F, p[a[i].S]) << " ";
        }
        else cout << a[i].F << " ";
    }
    cout << "\n";

    return 0;
}