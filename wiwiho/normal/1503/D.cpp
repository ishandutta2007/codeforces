#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> dsu, mn;

int findDSU(int a){
    if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a);
    b = findDSU(b);
    mn[a] = min(mn[a], mn[b]);
    dsu[b] = a;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    dsu.resize(2 * n + 1);
    mn.resize(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++) dsu[i] = i, mn[i] = i;

    vector<int> e(2 * n + 1);
    vector<bool> r(2 * n + 1);
    vector<int> clr(2 * n + 1, -1);
    int mxl = 0, mnr = 2 * n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
            r[a] = true;
        }
        e[b] = a;
        mxl = max(mxl, a);
        mnr = min(mnr, b);
    }
    if(mnr < mxl){
//        cerr << mxl << " " << mnr << "\n";
        cout << "-1\n";
        return 0;
    }

    set<int> st;
    for(int i = 1; i <= 2 * n; i++){
        if(!e[i]) continue;

        int l = e[i];
        clr[l] = 0;

        if(st.empty()){
            st.insert(l);
            continue;
        }

        while(!st.empty() && *st.begin() <= l){
            int now = *st.begin();
//            cerr << i << " " << l << " " << now << "  ";
//            printv(clr, cerr);
            if(clr[now] == 1){
                cout << "-1\n";
                return 0;
            }
            st.erase(st.begin());
            unionDSU(l, now);
            clr[l] = 1;
        }

        st.insert(mn[findDSU(l)]);
        st.insert(l);
    }
//    printv(dsu, cerr);

    vector<vector<int>> cnt(2 * n + 1, vector<int>(2));
    for(int i = 1; i <= 2 * n; i++){
        if(e[i]) continue;
        int p = findDSU(i);
        if(r[i]){
            if(clr[i] == 0) cnt[p][0]++;
            else cnt[p][1]++;
        }
        else{
            if(clr[i] == 0) cnt[p][1]++;
            else cnt[p][0]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(!e[i] && dsu[i] == i) ans += min(cnt[i][0], cnt[i][1]);
    }
    cout << ans << "\n";

    return 0;
}