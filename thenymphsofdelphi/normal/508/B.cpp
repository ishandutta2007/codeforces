#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e3 + 5;

string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    bool ck = 0;
    Fora(&v, s){
        if ((v - '0') % 2 == 0){
            ck = 1;
            break;
        }
    }
    if (!ck){
        cout << -1 << endl;
        return 0;
    }
    For(i, 0, isz(s) - 1){
        if ((s[i] - '0') % 2 == 0 && s[i] < s.back()){
            swap(s[i], s.back());
            cout << s << endl;
            return 0;
        }
    }
    FordE(i, isz(s) - 2, 0){
        if ((s[i] - '0') % 2 == 0){
            swap(s[i], s.back());
            cout << s << endl;
            return 0;
        }
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/