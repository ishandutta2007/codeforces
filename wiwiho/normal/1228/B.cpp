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

const ll MOD = 1000000007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        int r;
        cin >> r;
        for(int j = 0; j < r; j++) a[i][j] = 1;
        if(r < w) a[i][r] = 2;
    }

    for(int i = 0; i < w; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++){
            if(a[j][i] == 2){
                cout << "0\n";
                return 0;
            }
            a[j][i] = 1;
        }
        if(c < h){
            if(a[c][i] == 1){
                cout << "0\n";
                return 0;
            }
            a[c][i] = 2;
        }
    }

    ll cnt = 0;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(a[i][j] == 0) cnt++;

    ll now = 1;
    ll base = 2;
    for(int i = 0; (1LL << i) <= cnt; i++){
        if((1LL << i) & cnt) now = now * base % MOD;
        base = base * base % MOD;
    }

    cout << (now % MOD) << "\n";

    return 0;
}