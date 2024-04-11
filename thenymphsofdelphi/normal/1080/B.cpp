#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)

#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')

#define pque priority_queue
#define mts multiset
//typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int sum(int x){
    if (x == 0) return 0;
    return ((x & 1) ? (-((x + 1) / 2)) : ((x + 1) / 2));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int l, r;
        cin >> l >> r;
        int ans = sum(r) - sum(l - 1);
        cout << ans << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5
1 3
2 5
5 5
4 4
2 3

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
-2
-2
-5
4
-1

==============================    |
----------------------------------+
*/