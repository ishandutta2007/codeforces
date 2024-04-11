#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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

#define left __left__

const int K = 5 + 5, K2 = 32 + 5, mod = 998244353;

int k, A, h;
int powA[K2];
int pos[K];

int shift[K];
map <int, int> mpp;
vector <int> left;
int msk;
int val;

int ans[K2];

void backtrack(int u) {
    if (u == k) {
        int old_val = val;
        val += (left[0] + 1) * powA[pos[u]] % mod;
        if (val >= mod) {
            val -= mod;
        }
        mpp[val] = msk;
        val = old_val;
        return;
    }
    vi old_left = left; int old_msk = msk; int old_val = val;
    For(tmsk, 0, (1 << (1 << (k - u - 1)))){
        left.clear();
        For(i, 0, (1 << (k - u - 1))){
            if (tmsk & (1 << i)){
                left.emplace_back(old_left[2 * i]);
                val += (old_left[2 * i + 1] + 1) * powA[pos[u]] % mod;
                if (val >= mod){
                    val -= mod;
                }
            }
            else{
                val += (old_left[2 * i] + 1) * powA[pos[u]] % mod;
                if (val >= mod){
                    val -= mod;
                }
                left.emplace_back(old_left[2 * i + 1]);
            }
        }
        msk |= tmsk << shift[u];
        backtrack(u + 1);
        msk = old_msk;
        val = old_val;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> k >> A >> h;
    powA[0] = 1;
    ForE(i, 1, (1 << k)){
        powA[i] = powA[i - 1] * A % mod;
    }
    For(i, 0, k){
        pos[i] = (1 << (k - i - 1)) + 1;
    }
    pos[k] = 1;
    shift[1] = 0;
    For(i, 2, k){
        shift[i] = shift[i - 1] + (1 << (k - i));
    }
    for (int i = 0; i < (1 << k); i += 2){
        left.emplace_back(i);
    }
    for (int i = 1; i < (1 << k); i += 2){
        val += (i + 1) * powA[pos[0]] % mod;
        if (val >= mod){
            val -= mod;
        }
        ans[i] = pos[0];
    }
    backtrack(1);
    For(msk2, 0, (1 << (1 << (k - 1)))){
        int val2 = 0, idx = 0;
        For(i, 1, k){
            For(j, 0, (1 << (k - i - 1))){
                if (msk2 & (1 << idx)){
                    val2 -= powA[pos[0]] - powA[pos[i]];
                    if (val2 >= mod){
                        val2 -= mod;
                    }
                    if (val2 < 0){
                        val2 += mod;
                    }
                }
                idx++;
            }
        }
        if (msk2 & (1 << idx)){
            val2 -= powA[pos[0]] - powA[pos[k]];
            if (val2 >= mod){
                val2 -= mod;
            }
            if (val2 < 0){
                val2 += mod;
            }
        }
        int val1 = h - val2;
        if (val1 < 0){
            val1 += mod;
        }
        if (mpp.count(val1)){
            int msk1 = mpp[val1];
            left.clear();
            for (int i = 0; i < (1 << k); i += 2){
                left.emplace_back(i);
            }
            idx = 0;
            For(u, 1, k){
                int tmsk1 = msk1 & ((1 << (1 << (k - u - 1))) - 1);
                vi old_left = left;
                left.clear();
                For(i, 0, (1 << (k - u - 1))){
                    if (tmsk1 & (1 << i)){
                        left.emplace_back(old_left[2 * i]);
                        ans[old_left[2 * i + 1]] = pos[u];
                        if (msk2 & (1 << idx)){
                            swap(ans[old_left[2 * i + 1]], ans[old_left[2 * i + 1] + 1]);
                        }
                    }
                    else{
                        ans[old_left[2 * i]] = pos[u];
                        if (msk2 & (1 << idx)){
                            swap(ans[old_left[2 * i]], ans[old_left[2 * i] + 1]);
                        }
                        left.emplace_back(old_left[2 * i + 1]);
                    }
                    idx++;
                }
                msk1 >>= (1 << (k - u - 1));
            }
            ans[left[0]] = pos[k];
            if (msk2 & (1 << idx)){
                swap(ans[left[0]], ans[left[0] + 1]);
            }
            For(i, 0, (1 << k)){
                cout << ans[i] << ' ';
            } cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
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