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
 
    int T;
    cin >> T;

    while(T--){

        string s;
        cin >> s;

        ll ans = 0;

        int n = s.size();
        vector<int> f0(n);

        for(int i = 0; i < n; i++){

            if(i - 1 >= 0 && s[i - 1] == '0') f0[i] = f0[i - 1];
            else f0[i] = i;

            int t = 0;
            for(int j = 0; (1 << j) <= n && i - j >= 0; j++){

                if(s[i - j] != '1') continue;
                t += (1 << j);
                if(f0[i - j] <= i - t + 1){
                    ans++;
                    //cerr << i << " " << j << " " << t << " " << ans << "\n";
                }

            }

        }
        //printv(f0, cerr);

        cout << ans << "\n";

    }
 
    return 0;
}