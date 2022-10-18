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

        vector<int> s(n);
        int one = 0, zero = 0;
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            s[i] = str.size();
            for(char c : str){
                if(c == '0') zero++;
                else one++;
            }
        }
        lsort(s);

        int center = 0;
        if(one % 2){
            center++;
            one--;
        }
        if(zero % 2){
            center++;
            zero--;
        }
        one /= 2;
        zero /= 2;

        vector<int> ts(n);
        int lst = 0;
        for(int i = 0; i < n; i++){
            int t = s[i] / 2;
            int t1 = min(t, one);
            one -= t1; t -= t1;
            int t0 = min(t, zero);
            zero -= t0; t -= t0;
            if(t > 0){
                one += t1;
                zero += t0;
                break;
            }
            lst = i;
            ts[i] = t;
            s[i] %= 2;
        }

        center += (one + zero) * 2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 1){
                if(center == 0){
                    for(; lst > i; lst--){
                        if(ts[lst]){
                            center += ts[lst] * 2;
                            s[lst] = 2;
                            lst--;
                            break;
                        }
                    }
                }
                if(!center) continue;
                center--;
                s[i] = 0;
            }
            if(s[i] == 0) ans++;
        }
        cout << ans << "\n";

    }

    return 0;
}