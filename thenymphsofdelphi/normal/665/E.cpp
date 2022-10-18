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

const int N = 1e6 + 5, M = 30;

struct trie{
    struct node{
        int nxt[2];
        int val;

        node(){
            nxt[0] = nxt[1] = -1;
            val = 0;
        }
    };

    vector <node> vnode;

    trie(){
        vnode.assign(1, node());
    }

    void insert(int x){
        int u = 0;
        FordE(i, M - 1, 0){
            vnode[u].val++;
            int bit = ((x & (1 << i)) ? 1 : 0);
            if (vnode[u].nxt[bit] == -1){
                vnode[u].nxt[bit] = isz(vnode);
                vnode.emplace_back();
            }
            u = vnode[u].nxt[bit];
        }
        vnode[u].val++;
    }

    int get(int x, int k){
        int ans = 0;
        int u = 0;
        FordE(i, M - 1, 0){
            int bitx = ((x & (1 << i)) ? 1 : 0);
            int bitk = ((k & (1 << i)) ? 1 : 0);
            if (bitk == 0){
                if (vnode[u].nxt[1 ^ bitx] != -1){
                    ans += vnode[vnode[u].nxt[1 ^ bitx]].val;
                }
            }
            if (vnode[u].nxt[bitx ^ bitk] == -1){
                return ans;
            }
            u = vnode[u].nxt[bitx ^ bitk];
        }
        ans += vnode[u].val;
        return ans;
    }
} cac;

int n, k;
int a[N];

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }

    cac.insert(0);
    int s = 0;
    ForE(i, 1, n){
        s ^= a[i];
        ans += cac.get(s, k);
        cac.insert(s);
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