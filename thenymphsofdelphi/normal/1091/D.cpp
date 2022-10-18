#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(indx, a, b) for (int indx = a; indx < b; indx++)
#define ForE(indx, a, b) for (int indx = a; indx <= b; indx++)
#define Ford(indx, a, b) for (int indx = a; indx > b; indx--)
#define FordE(indx, a, b) for (int indx = a; indx >= b; indx--)
#define Fora(indx, a) for (auto indx : a)

#define PrintV(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << ' ';
#define PrintVl(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << endl;
#define Ptest(x) return cout << x, 0;
#define Pmtest(x) cout << x << endl; continue;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)
#define mset(x) memset(x, 0, sizeof(x));

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e6 + 5, mod = 998244353, inf = 1e18 + 7;

int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    a[n + 1] = 1;
    FordE(i, n, 1){
        a[i] = (a[i + 1] * i) % mod;
    }
    int ans = a[1];
    //cout << ans << endl;
    Ford(i, n - 1, 0){
        int t = ((i - 1) * (n - i)) % mod;
        t = (t * a[i + 1]) % mod;
        ans = (ans + t) % mod;
    }
    cout << ans << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |
10

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
30052700

------------------------------    |
==================================+
*/