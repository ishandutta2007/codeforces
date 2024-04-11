#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

int n, x, y;
string s;
int cnt0[N], cnt1[N];
ll ans = 1e18 + 7, tans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s; n = s.length(); s = ' ' + s;
    cin >> x >> y;
    ForE(i, 1, n){
        cnt0[i] = cnt0[i - 1]; cnt1[i] = cnt1[i - 1];
        if (s[i] == '0'){
            cnt0[i]++;
        }
        else if (s[i] == '1'){
            cnt1[i]++;
        }
    }
    tans = 0;
    ForE(i, 1, n){
        if (s[i] == '0'){
            tans += (ll)(n - i - (cnt0[n] - cnt0[i])) * x;
        }
        else{
            tans += (ll)(cnt0[n] - cnt0[i]) * y;
        }
    }
    ForE(i, 1, n){
        if (s[i] == '?'){
            tans -= (ll)(i - 1 - cnt1[i - 1]) * x + (ll)(cnt0[n] - cnt0[i]) * y;
            tans += (ll)cnt1[i - 1] * y + (ll)(n - i - (cnt0[n] - cnt0[i])) * x;
        }
        ans = min(ans, tans);
    }
    tans = 0;
    ForE(i, 1, n){
        if (s[i] == '1'){
            tans += (ll)(n - i - (cnt1[n] - cnt1[i])) * y;
        }
        else{
            tans += (ll)(cnt1[n] - cnt1[i]) * x;
        }
    }
    ForE(i, 1, n){
        if (s[i] == '?'){
            tans -= (ll)(i - 1 - cnt0[i - 1]) * y + (ll)(cnt1[n] - cnt1[i]) * x;
            tans += (ll)cnt0[i - 1] * x + (ll)(n - i - (cnt1[n] - cnt1[i])) * y;
        }
        ans = min(ans, tans);
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