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

template <typename T> using ordered_set =
tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 5;

int n;
int a[N];

set <int> stt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    stt.clear();
    FordE(i, n, 1){
        if (a[i] % (i + 1)){
            while (1){
                int idx = i - 1 + isz(stt);
                for (auto itr = stt.rbegin(); itr != stt.rend(); itr++){
                    int j = *itr;
                    if (a[j] % (idx + 1)){
                        stt.erase(j);
                        break;
                    }
                    idx--;
                }
                if (idx == i - 1){
                    break;
                }
            }
        }
        else{
            stt.insert(i);
        }
    }
    if (isz(stt) == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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