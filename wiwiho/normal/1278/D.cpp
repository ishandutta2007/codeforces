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

vector<int> dsu;

int findDSU(int n){
    if(dsu[n] != n) dsu[n] = findDSU(dsu[n]);
    return dsu[n];
}

void unionDSU(int a, int b){
    dsu[findDSU(a)] = findDSU(b);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> a(2 * n + 1);
    vector<pii> s(n + 1);
    set<pii, greater<>> st;
    for(int i = 1; i <= n; i++){
        cin >> s[i].F >> s[i].S;
        a[s[i].F] = i;
        a[s[i].S] = -i;
    }

    dsu.resize(n + 1);
    for(int i = 1; i <= n; i++) dsu[i] = i;

    for(int i = 1; i <= 2 * n; i++){

        if(a[i] > 0){
            st.insert(mp(i, a[i]));
            continue;
        }

        int t = -a[i];
        st.erase(mp(s[t].F, t));
        for(pii p : st){
            if(p.F < s[t].F) break;
            if(findDSU(t) == findDSU(p.S)){
                //cerr << t << " " << p.S << "\n";
                //cerr << "test\n";
                cout << "NO\n";
                return 0;
            }
            unionDSU(t, p.S);
        }

    }

    for(int i = 2; i <= n; i++){
        if(findDSU(i) != findDSU(1)){
            //cerr << "test2\n";
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}