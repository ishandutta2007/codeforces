#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pdd;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e3 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, ans = 0;
pii a[N], b[N];

pdd intersect(pii A, pii B, pii C, pii D){
    ld a1 = 1.0 * B.se - 1.0 * A.se; 
    ld b1 = 1.0 * A.fi - 1.0 * B.fi; 
    ld c1 = 1.0 * a1 * A.fi + 1.0 * b1 * A.se;
    ld a2 = 1.0 * D.se - 1.0 * C.se;
    ld b2 = 1.0 * C.fi - 1.0 * D.fi;
    ld c2 = 1.0 * a2 * C.fi + 1.0 * b2 * C.se;
    ld det = 1.0 * a1 * b2 - 1.0 * a2 * b1;
    if (det == 0){
        return {LDBL_MAX, LDBL_MAX};
    }
    else{
        ld x = 1.0 * (1.0 * b2 * c1 - 1.0 * b1 * c2) / det;
        ld y = 1.0 * (1.0 * a1 * c2 - 1.0 * a2 * c1) / det;
        return {x, y};
    }
}

bool ckin(pii A, pii B, pii C){
    if (C == A || C == B) return 1;
    if (((A.fi >= C.fi && C.fi >= B.fi) || (A.fi <= C.fi && C.fi <= B.fi)) && ((A.se >= C.se && C.se >= B.se) || (A.se <= C.se && C.se <= B.se))) return 1;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
    }
    ForE(i, 1, n){
        ans += __gcd(abs(a[i].fi - b[i].fi), abs(a[i].se - b[i].se)) + 1;
        //cout << __gcd(abs(a[i].fi - b[i].fi), abs(a[i].se - b[i].se)) + 1 << endl;
        set <pii > st;
        For(j, 1, i){
            pdd tmp = intersect(a[i], b[i], a[j], b[j]);
            if (tmp.fi == LDBL_MAX) continue;
            pii tmp2;
            tmp2.fi = round(tmp.fi);
            tmp2.se = round(tmp.se);
            //cout << i << ' ' << j << ' ' << tmp2.fi << ' ' << tmp2.se << endl;
            if (abs(1.0 * tmp2.fi - tmp.fi) <= 1e-7 && abs(1.0 * tmp2.se - tmp.se) <= 1e-7 && ckin(a[i], b[i], tmp2) && ckin(a[j], b[j], tmp2)){
                //cout << "YES" << endl;
                st.insert(tmp2);
            }
        }
        //cout << st.size() << endl;
        ans -= st.size();
        //cout << "ANS " << ans << endl;
    }
    cout << ans;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/