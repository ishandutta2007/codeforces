#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
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

#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int sot(string s){
	int ans = 0;
	Fora(v, s){
		ans *= 10;
		ans += (v - '0');
	}
	return ans;
}

string tos(int x){
	if (x == 0) return "0";
	string s = "";
	while (x){
		s += (char)(x % 10 + '0');
		x /= 10;
	}
	reverse(bend(s));
	return s;
}

bool cmp(string a, string b){
	if (a.length() != b.length()) return a.length() < b.length();
	return strcmp(a.c_str(), b.c_str()) < 0;
}

string add(string a, string b){
    string ans = "";
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int carry = 0, rem;
    for (int i = a.length() - 1; i >= 0; --i) {
        rem = (a[i] - '0' + b[i] - '0') + carry;
        ans = (char(rem % 10 + '0')) + ans;
        carry = rem / 10;
    }
    if (carry > 0) ans = "1" + ans;
    return ans;
}

string sub(string a, string b){
    string ans = "";
    bool neg = 0;
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    if (a < b) swap(a, b), neg = 1;
    int carry = 0, rem;
    for (int i = a.length() - 1; i >= 0; --i) {
        rem = a[i] - b[i] - carry;
        carry = 0;
        while (rem < 0) {
            ++ carry;
            rem += 10;
        }
        ans = (char(rem % 10 + '0')) + ans;
    }
    while (ans.length() > 1 && ans[0] == '0') ans.erase(0, 1);
    if (neg) ans = "-" + ans;
    return ans;
}

string mul(string a, string b){
    long long sav[2050];
    for (int i = 0; i < 2050; i++)
        sav[i] = 0;
    string ans = "";
    int carry = 0, rem;
    a = "0" + a;
    b = "0" + b;
    for (int i = a.length() - 1; i >= 0; --i)
        for (int j = b.length() - 1; j >= 0; --j)
            sav[i + j] += ((a[i] - '0') * (b[j] - '0'));
    for (int i = a.length() + b.length() - 2; i >= 0; --i){
        rem = sav[i] + carry;
        carry = rem / 10;
        ans = char(rem % 10 + '0') + ans;
    }
    while (ans.length() > 1 && ans[0] == '0') ans.erase(0, 1);
    return ans;
}

string divnum(string a, int b){
    string ans;
    int idx = 0; 
    int tmp = a[idx] - '0'; 
    while (tmp < b){
       tmp = tmp * 10 + (a[++idx] - '0');
   }
    while (a.size() > idx){
        ans += (tmp / b) + '0';
        tmp = (tmp % b) * 10 + a[++idx] - '0'; 
    }
    if (ans.length() == 0){
        return "0";
    }
    return ans; 
}

int modnum(string a, int b){
	string c = divnum(a, b), d = mul(c, tos(b));
	return sot(sub(a, d));
}

int strgcd(string a, int b){
	return __gcd(modnum(a, b), b);
}

string lcm(string x, int y){
	return mul(divnum(x, strgcd(x, y)), tos(y));
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q = 1;
// cin >> q;
while (q--){
    string s, t; cin >> s >> t;
    reverse(bend(s)); while (s.back() == '0') s.pob(); if (s == "") s = "0"; reverse(bend(s));
    reverse(bend(t)); while (t.back() == '0') t.pob(); if (t == "") t = "0"; reverse(bend(t));
    if (cmp(s, t)) Ptest('<');
    if (cmp(t, s)) Ptest('>');
    cout << '=';
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