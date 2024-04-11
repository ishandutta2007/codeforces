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

// juckter quest

const int N = 1e2 + 5;

int n, u, r, d, l;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> u >> r >> d >> l;
    bool ck = 0;
    For(msk, 0, 16){
        int tu = u, tr = r, td = d, tl = l;
        if (msk & 1){
            tu--; tr--;
        }
        if (msk & 2){
            tr--; td--;
        }
        if (msk & 4){
            td--; tl--;
        }
        if (msk & 8){
            tl--; tu--;
        }
        if (0 <= tu && tu <= n - 2 && 0 <= tr && tr <= n - 2 && 0 <= td && td <= n - 2 &&
            0 <= tl && tl <= n - 2){
            ck = 1;
            break;
        }
    }
    if (ck){
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