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
const ll MAX = (1LL << 60);

int main(){
    StarBurstStream

    int q;
    cin >> q;

    while(q--){

        string s;
        cin >> s;

        int l = 0, r = 0, u = 0, d = 0;
        for(char c : s){
            if(c == 'L') l++;
            else if(c == 'R') r++;
            else if(c == 'U') u++;
            else d++;
        }
       // cerr << l << " " << r << " " << u << " " << d << "\n";

        int ans = 0;
        int t1 = min(u, d);
        ans += max(u, d) - t1;
        int t2 = min(l, r);
        ans += max(l, r) - t2;

        if(t1 > 1 && t2 == 0){
            ans += t1 - 1;
            t1 = 1;
        }
        else if(t2 > 1 && t1 == 0){
            ans += t2 - 1;
            t2 = 1;
        }
        //cerr << l << " " << r << " " << u << " " << d << "\n";

        cout << t1 + t1 + t2 + t2 <<"\n";
        for(int i = 0; i < t2; i++) cout << "L";
        for(int i = 0; i < t1; i++) cout << "U";
        for(int i = 0; i < t2; i++) cout << "R";
        for(int i = 0; i < t1; i++) cout << "D";
        cout << "\n";

    }

    return 0;
}