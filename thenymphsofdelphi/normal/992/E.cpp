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
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()){
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta){
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n, q;
vi a;
set <int> st[32];
bool start0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    a.resize(n);
    For(i, 0, n){
        cin >> a[i];
        if (!i && !a[i]){
            start0 = 1;
        }
        else if (a[i]){
            st[(int)(log2(a[i]))].insert(i);
        }
    }
    FenwickTree fwtree = FenwickTree(a);
    while (q--){
        int x, y, dif;
        cin >> x >> y;
        x--;
        dif = y - a[x];
        fwtree.add(x, dif);
        if (x == 0){
            if (y){
                start0 = 0;
            }
            else{
                start0 = 1;
            }
        }
        if ((a[x]) && (!y)){
            st[(int)(log2(a[x]))].erase(x);
        }
        else if ((!a[x]) && (y)){
            st[(int)(log2(y))].insert(x);
        }
        else if (((int)(log2(y))) != ((int)(log2(a[x])))){
            st[(int)(log2(a[x]))].erase(x);
            st[(int)(log2(y))].insert(x);
        }
        a[x] = y;
        bool ck = 0;
        //PrintA(a, n);
        //cout << endl;
        For(i, 0, 32){
            auto itr = st[i].begin();
            For(j, 0, min(2ll, (int)st[i].size())){
                if ((*itr) && fwtree.sum(*itr - 1) == a[*itr]){
                    ck = 1;
                    //cout << "A " << a[*itr] << ' ';
                    cout << *itr + 1 << endl;
                    break;
                }
                itr++;
            }
            if (ck){
                break;
            }
        }
        if (!ck){
            if (start0){
                ck = 1;
                cout << 1 << endl;
            }
        }
        if (!ck){
            cout << -1 << endl;
        }
    }
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