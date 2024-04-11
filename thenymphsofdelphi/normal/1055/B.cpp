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
#define isvowel(a) ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t, l, cnt = 0;
    int q, p, d;
    cin >> n >> t >> l;
    int a[n + 2];
    bool ck[n + 2];
    ck[0] = 0;
    ck[n + 1] = 0;
    ForE(i, 1, n){
        cin >> a[i];
        ck[i] = ((a[i] > l) ? 1 : 0);
    }
    bool c = 0;
    ForE(i, 1, n){
        if (ck[i]){
            if (!c){
                cnt++;
                c = 1;
            }
        }
        else{
            c = 0;
        }
    }
    while (t--){
        cin >> q;
        if (!q){
            cout << cnt << endl;
        }
        else{
            cin >> p >> d;
            a[p] += d;
            if (a[p] > l && (!ck[p])){
                if ((!ck[p - 1]) && (!ck[p + 1])){
                    cnt++;
                }
                if (ck[p - 1] && ck[p + 1]){
                    cnt--;
                }
                ck[p] = 1;
            }
        }
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
4 7 3
1 2 3 4
0
1 2 3
0
1 1 3
0
1 3 1
0
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
1
2
2
1
==============================    |
----------------------------------+
*/