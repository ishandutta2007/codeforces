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

const int N = 1e5 + 5;

int n; ll k;
string s;

int cnt[26];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("E.inp", "r", stdin);
    // freopen("E.out", "w", stdout);
    cin >> n >> k;
    cin >> s;
    k -= (1 << (s.back() - 'a')); s.pop_back();
    k += (1 << (s.back() - 'a')); s.pop_back();
    if (n == 2){
        if (k){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
        return 0;
    }
    Fora(&v, s){
        cnt[v - 'a']++;
    }
    FordE(i, 25, 0){
        ll fink = 1000000000000000000ll;
        ll tk = (ll)cnt[i] * (1 << i);
        ForE(j, 0, cnt[i]){
            if (abs(k - tk) < abs(fink)){
                fink = k - tk;
            }
            tk -= 2 * (1 << i);
        }
        k = fink;
    }
    if (k){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
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