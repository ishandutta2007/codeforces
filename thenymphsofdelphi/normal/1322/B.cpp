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

const int N = 4e5 + 5;

int n;
int a[N], b[N], bb[N];
ll ans;
int cnt0[N], cnt1[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        b[i] = i;
    }
    ForE(j, 0, 25){
        ForE(i, 1, n){
            cnt0[i] = cnt0[i - 1];
            cnt1[i] = cnt1[i - 1];
            if (a[b[i]] & (1 << j)){
                cnt1[i]++;
            }
            else{
                cnt0[i]++;
            }
        }
        if (!j){
            if ((ll)cnt0[n] * cnt1[n] % 2){
                ans |= (1 << j);
            }
        }
        else{
            ll cnt = 0;
            int idxb = n + 1, l, r;
            ForE(i, 1, n){
                while (idxb - 1 >= 1 && (a[b[idxb - 1]] & ((1 << j) - 1)) +
                                        (a[b[i]] & ((1 << j) - 1)) >= (1 << j)){
                    idxb--;
                }
                if (a[b[i]] & (1 << j)){
                    l = i + 1; r = idxb - 1;
                    if (l <= r){
                        cnt += cnt0[r] - cnt0[l - 1];
                    }
                    l = max(idxb, i + 1); r = n;
                    if (l <= r){
                        cnt += cnt1[r] - cnt1[l - 1];
                    }
                }
                else{
                    l = i + 1; r = idxb - 1;
                    if (l <= r){
                        cnt += cnt1[r] - cnt1[l - 1];
                    }
                    l = max(idxb, i + 1); r = n;
                    if (l <= r){
                        cnt += cnt0[r] - cnt0[l - 1];
                    }
                }
            }
            if (cnt & 1){
                ans |= (1 << j);
            }
        }
        int idxbb = 0;
        ForE(i, 1, n){
            if (!(a[b[i]] & (1 << j))){
                bb[++idxbb] = b[i];
            }
        }
        ForE(i, 1, n){
            if (a[b[i]] & (1 << j)){
                bb[++idxbb] = b[i];
            }
        }
        ForE(i, 1, n){
            b[i] = bb[i];
        }
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