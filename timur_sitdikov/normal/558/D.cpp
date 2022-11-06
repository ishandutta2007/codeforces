#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

set<pair<ll, ll> > st;
set<pair<ll, ll> >::iterator it, it1;

vector<pair<ll, ll> > vv_add, vv_del;

void solve(){
    int h, n, i, j, ans, curh;
    ll l, r, maxl, maxr, l1, r1;
    scanf("%d%d", &h, &n);
    l = 1ll;
    REP(i, 1, h){
        l <<= 1;
    }
    r = l * 2ll - 1ll;
    st.insert(mp(l, r));
    maxl = l;
    maxr = r;   
    REP(i, 0, n){
        scanf("%d%lld%lld%d", &curh, &l, &r, &ans);
        REP(j, 0, h - curh){
            l = min(2ll * l, maxr + 1ll);
            r = min(2ll * r + 1, maxr + 1ll); 
        }
        vv_del.clear();
        vv_add.clear();
        /*printf("# %lld %lld\n", l, r);
        FA(tmp_it, st){
            printf("%lld %lld\n", tmp_it->first, tmp_it->second);
        }
        printf("**********************************\n");*/
        if (ans == 1){
            for(it = st.begin(); it != st.end() && it->first < l; it++){
                l1 = it->first;
                r1 = it->second;
                if (l1 < l || r1 > r){                  
                    vv_del.pb(mp(l1, r1));
                    if (max(l, l1) <= min(r, r1)){
                        vv_add.pb(mp(max(l, l1), min(r, r1)));
                    }
                }
            }
            it = st.lower_bound(mp(r + 1, r + 1));
            if (it != st.begin()){
                it--;
            }
            for(; it != st.end(); it++){
                l1 = it->first;
                r1 = it->second;
                if (l1 < l || r1 > r){                  
                    vv_del.pb(mp(l1, r1));
                    if (max(l, l1) <= min(r, r1)){
                        vv_add.pb(mp(max(l, l1), min(r, r1)));
                    }
                }
            }
        }
        if (ans == 0){          
            it = st.lower_bound(mp(l, l));
            if (it != st.begin()){
                it--;
            }
            for(; it != st.end() && it->first <= r; it++){
                l1 = it->first;
                r1 = it->second;
                if (l1 <= r && r1 >= l){
                    vv_del.pb(mp(l1, r1));
                    if (l1 < l){
                        vv_add.pb(mp(l1, l - 1));
                    }
                    if (r1 > r){
                        vv_add.pb(mp(r + 1, r1));
                    }
                }
            }
        }
        REP(j, 0, SZ(vv_del)){
            //printf("# %lld %lld\n", vv_del[j].first, vv_del[j].second);
            st.erase(vv_del[j]);
        }
        REP(j, 0, SZ(vv_add)){
            //printf("# %lld %lld\n", vv_add[j].first, vv_add[j].second);
            st.insert(vv_add[j]);
        }
    }
    /*FA(tmp_it, st){
        printf("%lld %lld\n", tmp_it->first, tmp_it->second);
    }*/
    if (st.empty()){
        printf("Game cheated!\n");
        return;
    }
    it = st.begin();
    l = it->first;
    r = it->second;
    if (SZ(st) > 1 || l != r){
        printf("Data not sufficient!\n");
    } else {
        printf("%lld\n", l);
    }
}   


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}