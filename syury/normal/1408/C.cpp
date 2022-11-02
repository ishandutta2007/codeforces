//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;
const dbl inf = 1e10;
const dbl eps = 1e-12;

int n, l;
int a[N];

void solve(){
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int v1 = 1, v2 = 1;
    dbl lpos = 0, rpos = l;
    int lptr = 0, rptr = n - 1;
    dbl passed = 0;
    while(1){
        while(lptr < n && a[lptr] < lpos + eps){
            ++v1;
            ++lptr;
        }
        while(rptr >= 0 && a[rptr] > rpos - eps){
            ++v2;
            --rptr;
        }
        dbl dT = (rpos - lpos)/(v1 + v2);
        dbl nextL = (lptr < n) ? (a[lptr] - lpos)/v1 : inf;
        dbl nextR = (rptr >= 0) ? (rpos - a[rptr])/v2 : inf;
        dbl nextEvt = min({dT, nextL, nextR});
        if(fabs(dT - nextEvt) < eps){
            passed += dT;
            break;
        }
        else if(fabs(nextL - nextEvt) < eps){
            lpos = a[lptr];
            ++lptr;
            rpos -= v2 * nextL;
            v1 += 1;
            passed += nextL;
        }
        else{
            rpos = a[rptr];
            --rptr;
            lpos += v1 * nextR;
            v2 += 1;
            passed += nextR;
        }
    }
    cout << fixed << passed << '\n';
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}