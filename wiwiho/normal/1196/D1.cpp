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

char rgb[3] = {'R', 'G', 'B'};

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = MAX;
        for(int i = 0; i + k - 1 < n; i++){
            int t1 = 0, t2= 0, t3 = 0;
            for(int j = 0; j < k; j++){
                if(s[i + j] != rgb[j % 3]){
                    t1++;
                }
            }
            for(int j = 0; j < k; j++){
                if(s[i + j] != rgb[(j + 1) % 3]){
                    t2++;
                }
            }
            for(int j = 0; j < k; j++){
                if(s[i + j] != rgb[(j + 2) % 3]){
                    t3++;
                }
            }
            ans = min({ans, t1, t2, t3});
        }
        cout << ans << "\n";
    }

    return 0;
}