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
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.length();
    bool ck = 1;
    For(i, 0, n){
        if (s[i] != 'a'){
            ck = 0;
            break;
        }
    }
    if (ck){
        For(i, 0, n - 1) cout << 'a';
        cout << 'z';
        return 0;
    }
    int i = 0, j;
    while (s[i] == 'a') i++;
    j = i;
    while (j < n && s[j] != 'a') j++;
    j--;
    ForE(k, i, j) s[k] -= 1;
    cout << s;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
codeforces
==============================    |
abacaba
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
bncdenqbdr
==============================    |
aaacaba
==============================    |
----------------------------------+
*/