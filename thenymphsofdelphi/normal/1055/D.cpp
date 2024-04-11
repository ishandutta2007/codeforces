#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")

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

#define hash __hash__

const int N = 3e3 + 5, base = 131, mod = 998244853;

int n;
string s[N], t[N];

int pwbase[N];
int hashs[N][N], hasht[N][N];

void precalhash(){
    pwbase[0] = 1;
    For(i, 1, N){
        pwbase[i] = (ll)pwbase[i - 1] * base % mod;
    }
    ForE(i, 1, n){
        For(j, 0, isz(s[i])){
            hashs[i][j] = ((ll)(j ? hashs[i][j - 1] : 0) * base + s[i][j]) % mod;
        }
        For(j, 0, isz(t[i])){
            hasht[i][j] = ((ll)(j ? hasht[i][j - 1] : 0) * base + t[i][j]) % mod;
        }
    }
}

int cals(int i, int l, int r){
    int ans = hashs[i][r] - (ll)(l ? hashs[i][l - 1] : 0) * pwbase[r - l + 1] % mod;
    if (ans < 0) ans += mod;
    return ans;
}

int calt(int i, int l, int r){
    int ans = hasht[i][r] - (ll)(l ? hasht[i][l - 1] : 0) * pwbase[r - l + 1] % mod;
    if (ans < 0) ans += mod;
    return ans;
}

vector <tuple <int, int, int>> vidx;

string ms, mt;
int hashms, hashmt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> s[i];
    }
    ForE(i, 1, n){
        cin >> t[i];
    }

    precalhash();
    ForE(i, 1, n){
        int l = 0, r = isz(s[i]) - 1;
        while (l < isz(s[i]) and s[i][l] == t[i][l]){
            l++;
        }
        while (r >= 0 and s[i][r] == t[i][r]){
            r--;
        }
        if (l <= r){
            if (ms.empty()){
                ms = s[i].substr(l, r - l + 1);
                mt = t[i].substr(l, r - l + 1);
                For(j, 0, isz(ms)){
                    hashms = ((ll)hashms * base + ms[j]) % mod;
                }
                For(j, 0, isz(mt)){
                    hashmt = ((ll)hashmt * base + mt[j]) % mod;
                }
            }
            else{
                if (r - l + 1 != isz(ms) or cals(i, l, r) != hashms or calt(i, l, r) != hashmt){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            vidx.emplace_back(i, l, r);
        }
    }
    {
        int lo = 0, hi = N;
        Fora(&elem, vidx){
            hi = min(hi, get<1>(elem));
        }
        while (lo < hi){
            int mid = (lo + hi + 1) >> 1;
            int prefhashs = -1, prefhasht = -1;
            Fora(&elem, vidx){
                int tprefhashs = cals(get<0>(elem), get<1>(elem) - mid, get<1>(elem) - 1);
                int tprefhasht = calt(get<0>(elem), get<1>(elem) - mid, get<1>(elem) - 1);
                if (tprefhashs != prefhashs and prefhashs != -1){
                    prefhashs = -1;
                    break;
                }
                if (tprefhasht != prefhasht and prefhasht != -1){
                    prefhashs = -1;
                    break;
                }
                prefhashs = tprefhashs;
                prefhasht = tprefhasht;
            }
            if (prefhashs == -1){
                hi = mid - 1;
            }
            else{
                lo = mid;
            }
        }
        ms = s[get<0>(vidx[0])].substr(get<1>(vidx[0]) - lo, lo) + ms;
        mt = t[get<0>(vidx[0])].substr(get<1>(vidx[0]) - lo, lo) + mt;
    }
    {
        int lo = 0, hi = N;
        Fora(&elem, vidx){
            hi = min(hi, isz(s[get<0>(elem)]) - get<2>(elem) - 1);
        }
        while (lo < hi){
            int mid = (lo + hi + 1) >> 1;
            int prefhashs = -1, prefhasht = -1;
            Fora(&elem, vidx){
                int tprefhashs = cals(get<0>(elem), get<2>(elem) + 1, get<2>(elem) + mid);
                int tprefhasht = calt(get<0>(elem), get<2>(elem) + 1, get<2>(elem) + mid);
                if (tprefhashs != prefhashs and prefhashs != -1){
                    prefhashs = -1;
                    break;
                }
                if (tprefhasht != prefhasht and prefhasht != -1){
                    prefhashs = -1;
                    break;
                }
                prefhashs = tprefhashs;
                prefhasht = tprefhasht;
            }
            if (prefhashs == -1){
                hi = mid - 1;
            }
            else{
                lo = mid;
            }
        }
        ms += s[get<0>(vidx[0])].substr(get<2>(vidx[0]) + 1, lo);
        mt += t[get<0>(vidx[0])].substr(get<2>(vidx[0]) + 1, lo);
    }
    {
        hashms = 0;
        For(j, 0, isz(ms)){
            hashms = ((ll)hashms * base + ms[j]) % mod;
        }
        hashmt = 0;
        For(j, 0, isz(mt)){
            hashmt = ((ll)hashmt * base + mt[j]) % mod;
        }
        ForE(i, 1, n){
            For(j, isz(ms) - 1, isz(s[i])){
                if (cals(i, j - isz(ms) + 1, j) == hashms){
                    ForE(k, j - isz(ms) + 1, j){
                        s[i][k] = mt[k - j + isz(ms) - 1];
                    }
                    break;
                }
            }
            if (s[i] != t[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    cout << ms << endl << mt << endl;
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