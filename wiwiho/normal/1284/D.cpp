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

ostream &operator<<(ostream &o, pii p){
    return o << p.F << "," << p.S;
}

bool solve(int n, vector<pii > &a, vector<pii > &b){
    map<int, vector<pii>> e;
    for(int i = 0; i < n; i++){
        e[a[i].F].eb(mp(0, i));
        e[a[i].S + 1].eb(mp(1, i));
    }

    multiset<int> st, ed;
    bool ans = true;
    for(auto &p : e){
        for(pii i : p.S){
            if(i.F == 1) st.erase(st.find(b[i.S].F)), ed.erase(ed.find(b[i.S].S));
        }
        for(pii i : p.S){
            if(i.F != 0) continue;
            if(!ed.empty())
                if(b[i.S].F > *ed.begin() || b[i.S].S < *st.rbegin()){
                    return false;
                }
            st.insert(b[i.S].F), ed.insert(b[i.S].S);
        }
    }
    return true;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii > a(n), b(n);
    map<int, vector<pii>> e;
    for(int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S >> b[i].F >> b[i].S;
    }

    if(solve(n, a, b) && solve(n, b, a)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}