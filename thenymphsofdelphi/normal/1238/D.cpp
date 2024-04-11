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

const int N = 3e5 + 5;

ll ans;
int n;
string s;
int pref[N][2], suff[N][2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s; s = ' ' + s;
    ForE(i, 1, n){
        pref[i][0] = pref[i - 1][0] + 1; pref[i][1] = pref[i - 1][1] + 1;
        pref[i][1 - (s[i] - 'A')] = 0;
    }
    FordE(i, n, 1){
        suff[i][0] = suff[i + 1][0] + 1; suff[i][1] = suff[i + 1][1] + 1;
        suff[i][1 - (s[i] - 'A')] = 0;
    }
    // ForE(i, 1, n){
    //     cout << pref[i][0] << ' ' << pref[i][1] << ' ' << suff[i][0] << ' ' << suff[i][1] << endl;
    // }
    ans = (ll)n * (n + 1) / 2;
    ForE(i, 1, n){
        ans--;
        ans -= pref[i - 1][1 - (s[i] - 'A')];
        ans -= suff[i + 1][1 - (s[i] - 'A')];
    }
    ForE(i, 2, n){
        if (s[i] != s[i - 1]) ans++;
    }
    cout << ans;
}