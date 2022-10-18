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

    int k;
    cin >> k;

    while(k--){

        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pii> tmp;
        int mxcnt = 0;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]) tmp.eb(mp(s[i], t[i]));
            else{
                cnt[s[i] - 'a']++;
                mxcnt = max(mxcnt, cnt[s[i] - 'a']);
            }
        }

        if((tmp.size() == 0 && mxcnt > 1) || (tmp.size() == 2 && tmp[0] == tmp[1])) cout << "Yes\n";
        else cout << "No\n";

    }

    return 0;
}