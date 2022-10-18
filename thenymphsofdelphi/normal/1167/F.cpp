#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
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
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

struct query{
    int val, pos;
} a[N];

bool cmp(query x, query y){
    return x.val < y.val;
}

int n, ans;
int segl[4 * N], segr[4 * N];

void updl(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos){
        return;
    }
    if (l == r){
        segl[id] = (val * pos) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    updl(id * 2, l, mid, pos, val);
    updl(id * 2 + 1, mid + 1, r, pos, val);
    segl[id] = (segl[id * 2] + segl[id * 2 + 1]) % mod;
}

int getl(int id, int l, int r, int u, int v){
    if (l > v || r < u){
        return 0;
    }
    if (l >= u && r <= v){
        return segl[id];
    }
    int mid = (l + r) >> 1;
    return (getl(id * 2, l, mid, u, v) + getl(id * 2 + 1, mid + 1, r, u, v)) % mod;
}

void updr(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos){
        return;
    }
    if (l == r){
        segr[id] = (val * (n - pos + 1)) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    updr(id * 2, l, mid, pos, val);
    updr(id * 2 + 1, mid + 1, r, pos, val);
    segr[id] = (segr[id * 2] + segr[id * 2 + 1]) % mod;
}

int getr(int id, int l, int r, int u, int v){
    if (l > v || r < u){
        return 0;
    }
    if (l >= u && r <= v){
        return segr[id];
    }
    int mid = (l + r) >> 1;
    return (getr(id * 2, l, mid, u, v) + getr(id * 2 + 1, mid + 1, r, u, v)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].val;
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp);
    ForE(i, 1, n){
        updl(1, 1, n, a[i].pos, 1);
        updr(1, 1, n, a[i].pos, 1);
        int sum1 = getl(1, 1, n, 1, a[i].pos), sum2 = 0;
        if (a[i].pos < n){
            sum2 = getr(1, 1, n, a[i].pos + 1, n);
        }
        int tmp = ((sum1 * (n - a[i].pos + 1) % mod) % mod + (sum2 * a[i].pos % mod) % mod) % mod;
        ans = (ans + (a[i].val * tmp % mod) % mod) % mod;
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