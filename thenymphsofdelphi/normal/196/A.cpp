#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    string s; cin >> s;
    int l = 0;
    while (l < isz(s)){
        int cnt[26], lst[26]; memset(cnt, 0, sizeof(cnt)); memset(lst, -1, sizeof(lst));
        For(i, l, isz(s)){
            cnt[s[i] - 'a']++; lst[s[i] - 'a'] = i;
        }
        FordE(i, 25, 0){
            if (cnt[i]){
                ForE(j, 1, cnt[i]){
                    cout << (char)(i + 'a');
                }
                l = lst[i] + 1;
                break;
            }
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