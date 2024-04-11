#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
#define ld long double
#define endl '\n'
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

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define debug(args...){ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

// Functions

#define mset(a) memset(a, 0, sizeof(a));
#define srtV(a) sort(a.begin(), a.end());
#define srtA(a, n) sort(a, a + n);

// Data Structure

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e3 + 5, maxn = 2e3 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    a = (a + 1) / 2;
    b = (b + 1) / 2;
    c = (c + 1) / 2;
    int ans = 0;
    ans = max(ans, 3 * a + 27);
    ans = max(ans, 3 * b + 28);
    ans = max(ans, 3 * c + 29);
    cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
1 3 2

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
34
==============================    |
----------------------------------+
*/