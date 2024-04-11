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

const int N = 2e5 + 5;

int n, m;
vi na, pa, nb, pb;
vi nc, pc, nd, pd;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    na.clear(); pa.clear(); nb.clear(); pb.clear();
    nc.clear(); pc.clear(); nd.clear(); pd.clear();
    cin >> n >> m;
    ForE(i, 1, n){
        int x; cin >> x;
        if (x < 0){
            na.push_back(-x);
        }
        else{
            pa.push_back(x);
        }
    }
    ForE(i, 1, m){
        int x; cin >> x;
        if (x < 0){
            nb.push_back(-x);
        }
        else{
            pb.push_back(x);
        }
    }
    sort(bend(na)); sort(bend(pa)); sort(bend(nb)); sort(bend(pb));
    int ans = 0, tans;
    if (isz(na) >= 1 && isz(nb) >= 1){
        nc.resize(isz(nb));
        For(i, 0, isz(nc)){
            int x = upper_bound(bend(na), nb[i]) - na.begin() - 1;
            if (x == -1){
                nc[i] = 0;
                continue;
            }
            nc[i] = i - (lower_bound(bend(nb), nb[i] - x) - nb.begin()) + 1;
        }
        nd.resize(isz(nb));
        FordE(i, isz(nd) - 1, 0){
            nd[i] = (i == isz(nd) - 1 ? 0 : nd[i + 1]);
            int x = lower_bound(bend(na), nb[i]) - na.begin();
            if (x < isz(na) && na[x] == nb[i]){
                nd[i]++;
            }
        }
        tans = nd[0];
        For(i, 0, isz(nc)){
            tans = max(tans, nc[i] + (i == isz(nc) - 1 ? 0 : nd[i + 1]));
        }
        ans += tans;
    }
    if (isz(pa) >= 1 && isz(pb) >= 1){
        pc.resize(isz(pb));
        For(i, 0, isz(pc)){
            int x = upper_bound(bend(pa), pb[i]) - pa.begin() - 1;
            if (x == -1){
                pc[i] = 0;
                continue;
            }
            pc[i] = i - (lower_bound(bend(pb), pb[i] - x) - pb.begin()) + 1;
        }
        pd.resize(isz(pb));
        FordE(i, isz(pd) - 1, 0){
            pd[i] = (i == isz(pd) - 1 ? 0 : pd[i + 1]);
            int x = lower_bound(bend(pa), pb[i]) - pa.begin();
            if (x < isz(pa) && pa[x] == pb[i]){
                pd[i]++;
            }
        }
        tans = pd[0];
        For(i, 0, isz(pc)){
            tans = max(tans, pc[i] + (i == isz(pc) - 1 ? 0 : pd[i + 1]));
        }
        ans += tans;
    }
    cout << ans << endl;
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