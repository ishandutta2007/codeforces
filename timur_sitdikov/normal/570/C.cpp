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
const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;

set <pii> st;
set <pii> :: iterator it, it1;
char s[MAXN];

void solve(){
    int n, i, l1, r1, l2, r2, q, x, cnt, ans;
    char sq[10];
    scanf("%d%d%s", &n, &q, &s[0]);
    cnt = 0;
    REP(i, 0, n + 1){
        if (s[i] == '.'){
            cnt++;
            if (i == 0 || s[i - 1] != '.'){
                l1 = i;
            }
        } else {
            if (i != 0 && s[i - 1] == '.'){
                st.insert(mp(l1, i - 1));
            }
        }
    }
    REP(i, 0, q){
        scanf("%d%s", &x, &sq[0]);
        x--;
        it = st.lower_bound(mp(x + 1, x + 1));
        it1 = it;
        if (it1 != st.end()){
            l2 = it1->first;
            r2 = it1->second;
        } else {
            l2 = r2 = INF;
        }
        if (it1 != st.begin()){
            it1--;
            if (it1 != st.end()){
                l1 = it1->first;
                r1 = it1->second;
            } else {
                l1 = r1 = -INF;
            }
        } else {
            l1 = r1 = -INF;
        }
        //printf("%d %d %d %d\n", l1, r1, l2, r2);
        if (sq[0] == '.'){
            if (r1 < x){
                cnt++;
                if (r1 == x - 1 && l2 == x + 1){
                    st.erase(mp(l1, r1));
                    st.erase(mp(l2, r2));
                    st.insert(mp(l1, r2));
                } else if (r1 == x - 1){
                    st.erase(mp(l1, r1));
                    st.insert(mp(l1, r1 + 1));
                } else if (l2 == x + 1){
                    st.erase(mp(l2, r2));
                    st.insert(mp(l2 - 1, r2));
                } else {
                    st.insert(mp(x, x));
                }
            }
        } else {
            if (r1 >= x){
                cnt--;
                st.erase(mp(l1, r1));
                if (l1 != x){
                    st.insert(mp(l1, x - 1));
                }
                if (r1 != x){
                    st.insert(mp(x + 1, r1));
                }
            }
        }
        ans = cnt - st.size();
        printf("%d\n", ans);
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