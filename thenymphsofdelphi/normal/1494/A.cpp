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

const int N = 50 + 5;

string s;
bool ans[3];
string t;

bool check(){
    int bal = 0;
    For(i, 0, isz(t)){
        if (t[i] == '('){
            bal++;
        }
        else{
            bal--;
            if (bal < 0){
                return 0;
            }
        }
    }
    if (bal != 0){
        return 0;
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> s;
    memset(ans, 0, sizeof(ans));
    if (s[0] == s.back()){
        cout << "NO" << endl;
        continue;
    }
    t = s;
    Fora(&v, t){
        if (v == s[0]){
            v = '(';
        }
        else if (v == s.back()){
            v = ')';
        }
    }
    For(i, 0, isz(s)){
        if (s[i] != s[0] && s[i] != s.back()){
            t[i] = '(';
        }
    }
    if (check()){
        cout << "YES" << endl;
        continue;
    }
    For(i, 0, isz(s)){
        if (s[i] != s[0] && s[i] != s.back()){
            t[i] = ')';
        }
    }
    if (check()){
        cout << "YES" << endl;
        continue;
    }
    cout << "NO" << endl;
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