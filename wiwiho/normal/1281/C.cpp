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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

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

        int x;
        cin >> x;

        string s;
        cin >> s;
        s.reserve(1000000);

        int l = 0;
        ll r = s.size();

        for(int i = 0; i < x; i++){
            l++;
            r = (r - 1 + MOD) % MOD;

            for(int j = 1; j < s[l - 1] - '0' && s.size() <= x; j++){
                int t = s.size();
                for(int k = t; k < t + r && k < x; k++) s += s[k - r];
            }

            r *= s[l - 1] - '0';
            r %= MOD;
        }

        //cerr << s << "\n";
        cout << (l + r) % MOD << "\n";

    }

    return 0;
}