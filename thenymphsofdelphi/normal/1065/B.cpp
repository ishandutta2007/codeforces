#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority_queue
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)
#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cout << max(0ll, n - m * 2) << ' ';
    if (m == 0){
        cout << n;
        return 0;
    }
    ForE(i, 2, n){
        if (m <= i * (i - 1) / 2){
            m = i;
            break;
        }
    }
	cout << max(0ll, n - m);
}

/*
----------------------------------+
INPUT:  						  |
==============================    |
4 2
==============================    |
3 1
==============================    |
----------------------------------+
OUTPUT: 						  |
==============================    |
0 1
==============================    |
1 1
==============================    |
----------------------------------+
*/