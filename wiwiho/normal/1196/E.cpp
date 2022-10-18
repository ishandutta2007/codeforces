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

int bcnt = 0;
int wcnt = 0;
int w, b;

set<pii> visit;

void dfs(int x, int y, bool c){ //c = 1 black, c = 0 white


    if(c && bcnt >= b) return;
    if(!c && wcnt >= w) return;
    //cerr << x << " " << y << " " << wcnt << " " << bcnt << " " << w << " " << b << " " << c << "\n";

    if(c) bcnt++;
    else wcnt++;
    visit.insert(mp(x, y));

    if(c && wcnt >= w) return;
    if(!c && bcnt >= b) return;

    if((x + 1) <= MAX && visit.find(mp(x + 1, y)) == visit.end()) dfs(x + 1, y, !c);
    if((y + 1) <= MAX && visit.find(mp(x, y + 1)) == visit.end()) dfs(x, y + 1, !c);
    if((x - 1) >= 1 && visit.find(mp(x - 1, y)) == visit.end()) dfs(x - 1, y, !c);
    if((y - 1) >= 1 && visit.find(mp(x, y - 1)) == visit.end()) dfs(x, y - 1, !c);

}

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){
        cin >> b >> w;
        bcnt = 0; wcnt = 0;

        visit.clear();

        dfs(500000000, 500000000, false);
        if(wcnt < w || bcnt < b){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(pii p : visit){
            cout << p.F << " " << p.S << "\n";
        }

    }

    return 0;
}