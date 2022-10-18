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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

set <int> ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s, t, j;
    cin >> n;
    s = sqrt(n);
    ForE(i, 1, s){
        if (n % i == 0){
            j = n / i;
            t = j;
            t += i * j * (j - 1) / 2;
            ans.insert(t);
            t = i;
            t += i * j * (i - 1) / 2;
            ans.insert(t);
        }
    }
    Fora(i, ans){
        cout << i << ' ';
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |
16


------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1 10 28 64 136

------------------------------    |
==================================+
*/