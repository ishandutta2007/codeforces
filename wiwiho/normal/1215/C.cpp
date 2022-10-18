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

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> ab;
    vector<int> ba;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' && t[i] == 'b'){
            ab.pb(i);
        }
        else if(s[i] == 'b' && t[i] == 'a'){
            ba.pb(i);
        }
    }

    if((ab.size() + ba.size()) % 2 != 0){
        cout << "-1\n";
        return 0;
    }

    vector<pii> ans;
    while(ab.size() > 1){
        pii p = mp(ab.back(), ab[ab.size() - 2]);
        ab.pop_back();
        ab.pop_back();
        ans.pb(p);
    }
    while(ba.size() > 1){
        pii p = mp(ba.back(), ba[ba.size() - 2]);
        ba.pop_back();
        ba.pop_back();
        ans.pb(p);
    }

    if(ab.size() && ba.size()){
        ans.pb(mp(ab.back(), ab.back()));
        ans.pb(mp(ab.back(), ba.back()));
    }

    cout << ans.size() << "\n";
    for(pii p : ans){
        cout << p.F + 1 << " " << p.S + 1 << "\n";
    }

    return 0;
}