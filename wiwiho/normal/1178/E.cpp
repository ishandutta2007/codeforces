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
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

#define tiiii tuple<int, int, int, int>
#define tget(t, i) get<i>(t)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 2147483647;

void f(string& s, int l, int r){
    if(r - l + 1 == 0) return;
    else if(r - l + 1 < 4){
        cout << s[l];
        return;
    }
    if(s[l] == s[r] || s[l] == s[r - 1]){
        cout << s[l];
        f(s, l + 2, r - 2);
        cout << s[l];
    }
    else{
        cout << s[l + 1];
        f(s, l + 2, r - 2);
        cout << s[l + 1];
    }
}

int main(){
    StarBurstStream

    string s;
    cin >> s;

    f(s, 0, s.size() - 1);

    return 0;
}