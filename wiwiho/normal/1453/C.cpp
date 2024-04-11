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

int f(vector<string>& a, int n, char d){
    int mxr = 0, mnr = n, mxc = 0, mnc = n;
    vector<int> rmx(n, 0), rmn(n, n), cmx(n, 0), cmn(n, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == d){
                mxr = max(mxr, i);
                mnr = min(mnr, i);
                mxc = max(mxc, j);
                mnc = min(mnc, j);
                rmx[i] = max(rmx[i], j);
                rmn[i] = min(rmn[i], j);
                cmx[j] = max(cmx[j], i);
                cmn[j] = min(cmn[j], i);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(rmn[i] == n) continue;
        ans = max(ans, (rmx[i] - rmn[i]) * max(i, n - 1 - i));
//        cerr << (rmx[i] - rmn[i]) * max(i, n - 1 - i) << " r " << i << "\n";
    }
    for(int i = 0; i < n; i++){
        if(cmn[i] == n) continue;
        ans = max(ans, (cmx[i] - cmn[i]) * max(i, n - 1 - i));
//        cout << (cmx[i] - cmn[i]) * max(i, n - 1 - i) << " c " << i << "\n";
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != d) continue;
            ans = max(ans, max(mxr - i, i - mnr) * max(j, n - 1 - j));
            ans = max(ans, max(mxc - j, j - mnc) * max(i, n - 1 - i));
        }
    }

    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<string> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < 10; i++) cout << f(a, n, '0' + i) << " ";
        cout << "\n";

    }

    return 0;
}