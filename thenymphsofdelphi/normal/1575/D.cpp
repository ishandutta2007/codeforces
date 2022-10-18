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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e6 + 5;

int len;
string s;

vi posx;
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s;
    len = isz(s);
    if (len == 1){
        if (s[0] == '0' or s[0] == '_' or s[0] == 'X'){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }
    if (len == 2){
        if (s[0] == 'X' and s[1] == 'X'){
            cout << 0 << endl;
            return 0;
        }
        if ((s[0] == '2' or s[0] == '_' or s[0] == 'X') and (s[1] == '5' or s[1] == '_' or s[1] == 'X')){
            ans++;
        }
        if ((s[0] == '5' or s[0] == '_' or s[0] == 'X') and (s[1] == '0' or s[1] == '_' or s[1] == 'X')){
            ans++;
        }
        if ((s[0] == '7' or s[0] == '_' or s[0] == 'X') and (s[1] == '5' or s[1] == '_' or s[1] == 'X')){
            ans++;
        }
        cout << ans << endl;
        return 0;
    }
    if (s[0] == '0'){
        cout << 0 << endl;
        return 0;
    }
    For(i, 0, len){
        if (s[i] == 'X'){
            posx.emplace_back(i);
        }
    }
    if (isz(posx) <= 1){
        if ((s[len - 2] == '0' or s[len - 2] == '_' or s[len - 2] == 'X') and (s[len - 1] == '0' or s[len - 1] == '_' or s[len - 1] == 'X')){
            ans++;
        }
        if ((s[len - 2] == '2' or s[len - 2] == '_' or s[len - 2] == 'X') and (s[len - 1] == '5' or s[len - 1] == '_' or s[len - 1] == 'X')){
            ans++;
        }
        if ((s[len - 2] == '5' or s[len - 2] == '_' or s[len - 2] == 'X') and (s[len - 1] == '0' or s[len - 1] == '_' or s[len - 1] == 'X')){
            ans++;
        }
        if ((s[len - 2] == '7' or s[len - 2] == '_' or s[len - 2] == 'X') and (s[len - 1] == '5' or s[len - 1] == '_' or s[len - 1] == 'X')){
            ans++;
        }
        FordE(i, len - 3, 1){
            if (s[i] == '_' or s[i] == 'X'){
                ans *= 10;
            }
        }
        if (s[0] == '_' or s[0] == 'X'){
            ans *= 9;
        }
        cout << ans << endl;
        return 0;
    }
    ForE(dx, 0, 9){
        string ss = s;
        int tans = 0;
        Fora(&c, s){
            if (c == 'X'){
                c = (char)(dx + '0');
            }
        }
        if ((s[len - 2] == '0' or s[len - 2] == '_') and (s[len - 1] == '0' or s[len - 1] == '_')){
            tans++;
        }
        if ((s[len - 2] == '2' or s[len - 2] == '_') and (s[len - 1] == '5' or s[len - 1] == '_')){
            tans++;
        }
        if ((s[len - 2] == '5' or s[len - 2] == '_') and (s[len - 1] == '0' or s[len - 1] == '_')){
            tans++;
        }
        if ((s[len - 2] == '7' or s[len - 2] == '_') and (s[len - 1] == '5' or s[len - 1] == '_')){
            tans++;
        }
        FordE(i, len - 3, 1){
            if (s[i] == '_' or s[i] == 'X'){
                tans *= 10;
            }
        }
        if (s[0] == '_' or s[0] == 'X'){
            tans *= 9;
        }
        else if (s[0] == '0'){
            tans = 0;
        }
        ans += tans;
        s = ss;
    }
    cout << ans << endl;
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