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

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << "Possible\n";
        cout << 1;
        return 0;
    }
    int a[n], b[n], c[n], cnt[n];
    bool ck[n];
    queue <int> idx[n + 1];
    memset(cnt, 0, sizeof(cnt));
    memset(ck, 0, sizeof(ck));
    For(i, 0, n){
        cin >> a[i];
        b[i] = n - a[i];
        cnt[a[i]]++;
        idx[b[i]].push(i);
    }
    if (cnt[0] == n){
        cout << "Possible\n";
        For(i, 0, n) cout << "1 ";
        return 0;
    }
    int t = 1;
    For(i, 0, n){
        if (ck[i]) continue;
        if (b[i] > cnt[a[i]]){
            //cout << i << ' ' << b[i] << ' ' << cnt[a[i]] << endl;
            Ptest("Impossible");
        }
        For(j, 0, b[i]){
            c[idx[b[i]].front()] = t;
            ck[idx[b[i]].front()] = 1;
            idx[b[i]].pop();
        }
        cnt[a[i]] -= b[i];
        t++;
    }
    cout << "Possible" << endl;
    For(i, 0, n){
        cout << c[i] << ' ';
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |
5
3 3 2 2 2
------------------------------    |
5
3 3 3 3 4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
Possible
1 1 2 2 2 
------------------------------    |
Possible
1 1 2 2 3
------------------------------    |
==================================+
*/