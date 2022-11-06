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
const int MAXD = 26;

set <pii> vv[MAXD];
set<pii>::iterator it;
char c[MAXN];

vector<pii> vv_del, vv_add;

void solve(){
    int n, q, i, j, l, r, l1, r1, t, aa, bb, cc;
    scanf("%d%d%s", &n, &q, &c[0]);
    REP(i, 0, n){
        vv[c[i] - 'a'].insert(mp(i, i));
    }
    for(; q; q--){
        scanf("%d%d%d", &l, &r, &t);
        l--;
        r--;
        if (!t){
            aa = MAXD - 1;
            bb = -1;
            cc = -1;
        } else {
            aa = 0;
            bb = MAXD;
            cc = 1;
        }
        int last_len = 0, cur_len;
        for(j = aa; j != bb; j += cc){
            vv_del.clear();
            vv_add.clear();
            it = vv[j].lower_bound(mp(l, l));
            if (it != vv[j].begin()){
                it--;
            }
            for(; it != vv[j].end() && it->first <= r; it++){
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
            cur_len = 0;
            REP(i, 0, SZ(vv_del)){
                cur_len += vv_del[i].second - vv_del[i].first + 1; 
            }
            REP(i, 0, SZ(vv_add)){
                cur_len -= vv_add[i].second - vv_add[i].first + 1;
            }
            if (cur_len > 0){
                vv_add.pb(mp(l + last_len, l + last_len + cur_len - 1));
            }
            REP(i, 0, SZ(vv_del)){
                vv[j].erase(vv_del[i]);
            }
            REP(i, 0, SZ(vv_add)){
                vv[j].insert(vv_add[i]);
            }
            last_len += cur_len;
        }
    }
    /*printf("#\n");
    return;*/
    REP(j, 0, MAXD){
        FA(tmp_it, vv[j]){
            //printf("%d %d %d\n", j, tmp_it->first, tmp_it->second);
            REP(i, tmp_it->first, tmp_it->second + 1){
                c[i] = j + 'a';
            }
        }
    }
    printf("%s\n", c);
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