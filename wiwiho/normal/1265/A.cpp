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

        bool ans = true;
        string s;
        cin >> s;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '?') continue;
            if((i == 0 || s[i - 1] != 'a') && (i == s.size() - 1 || s[i + 1] != 'a')) s[i] = 'a';
            else if((i == 0 || s[i - 1] != 'b') && (i == s.size() - 1 || s[i + 1] != 'b')) s[i] = 'b';
            else if((i == 0 || s[i - 1] != 'c') && (i == s.size() - 1 || s[i + 1] != 'c')) s[i] = 'c';
        }

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1]){
                ans = false;
                break;
            }
        }

        if(ans) cout << s << "\n";
        else cout << "-1\n";

    }

    return 0;
}