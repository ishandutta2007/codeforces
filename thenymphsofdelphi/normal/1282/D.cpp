#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 3e2 + 5;

int ask(string s){
    cout << s << endl;
    int x; cin >> x;
    if (x){
        return x;
    }
    exit(0);
}

string s;

string t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    t = string(300, 'a');
    int cnta = 300 - ask(t);
    t = string(300, 'b');
    int cntb = 300 - ask(t);
    s = string(cnta + cntb, 'a');
    int ans = cntb;
    For(i, 0, cnta + cntb - 1){
        s[i] = 'b';
        int tans = ask(s);
        if (tans > ans){
            s[i] = 'a';
        }
        else{
            ans = tans;
        }
    }
    int cnt = 0;
    For(i, 0, cnta + cntb - 1){
        if (s[i] == 'a') cnt++;
    }
    if (cnt == cnta){
        s.back() = 'b';
    }
    ask(s);
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