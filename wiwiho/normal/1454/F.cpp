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

vector<vector<int>> st;

int query(int l, int r){
    int lg = __lg(r - l + 1);
    return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<int> a(n);
        int mx = 0;
        vector<int> mxp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > mx){
                mx = a[i];
                mxp.clear();
            }
            if(a[i] == mx) mxp.eb(i);
        }

        if(mxp.size() >= 3){
            cout << "YES\n";
            cout << mxp[1] << " " << 1 << " " << n - mxp[1] - 1 << "\n";
            continue;
        }

        st.clear();
        st.resize(n, vector<int>(20));
        for(int i = 0; i < n; i++) st[i][0] = a[i];
        for(int i = 1; i < 20; i++){
            for(int j = 0; j + (1 << i) - 1 < n; j++){
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }

        int bp = n;
        int pmx = 0, smx = 0;
        bool ok = false;
        map<int, int> cnt;
        for(int i = 0; i < n && i < bp; i++){
            pmx = max(pmx, a[i]);
            while(smx <= pmx && i < bp - 1){
                if(a[bp - 1] > pmx) break;
                bp--;
                smx = max(smx, a[bp]);
                cnt[a[bp]]++;
            }
//            cerr << i << " " << bp << "\n";
            if(pmx != smx) continue;
            if(i + 1 == bp){
                if(a[bp] != pmx || cnt[a[bp]] == 1) continue;
                cout << "YES\n";
                cout << i + 1 << " " << 1 << " " << n - bp - 1 << "\n";
                ok = true;
                break;
            }
            if(query(i + 1, bp - 1) < pmx) continue;
            if(query(i + 1, bp - 1) == pmx){
                cout << "YES\n";
                cout << i + 1 << " " << bp - i - 1 << " " << n - bp << "\n";
                ok = true;
                break;
            }
            if(a[bp] == pmx && cnt[a[bp]] > 1){
                cout << "YES\n";
                cout << i + 1 << " " << bp - i << " " << n - bp - 1 << "\n";
                ok = true;
                break;
            }
        }
        if(!ok) cout << "NO\n";

    }

    return 0;
}