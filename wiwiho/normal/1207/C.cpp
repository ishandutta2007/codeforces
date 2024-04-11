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

    int T;
    cin >> T;
    while(T--){

        ll n, a, b;
        cin >> n >> a >> b;

        vector<int> zero;
        string s;
        cin >> s;
        ll ac = 0, bc = 0;
        bool t = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                t = true;
                if(s[i] == s[i - 1]) bc++;
                else bc += 2;
                continue;
            }
            if(!t) continue;
            if(s[i] == s[i - 1]) zero.back()++;
            else zero.pb(1);
        }
        if(t){
            ac += 2;
            zero.pob;
        }

        for(int i : zero){
            if(i == 1) continue;
            if(2 * a < (i - 1) * b) ac += 2;
            else bc += i - 1;
        }

        cout << (bc + n + 1) * b + (ac + n) * a << "\n";

    }

    return 0;
}