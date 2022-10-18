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

const int N = 1e6 + 5, mod = 1e9 + 7;

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = (ll)ans * x % mod;
        x = (ll)x * x % mod;
        y >>= 1;
    }
    return ans;
}

int n;
int p[N];
bool ck[N];
vi cycleLen;

int cal(int cnt1, int cnt2){
    int ans = 0, tmp = min(cnt1, cnt2); ans += tmp; cnt1 -= tmp; cnt2 -= tmp;
    if (cnt1){
        ans += cnt1 / 3 * 2;
    }
    if (cnt2){
        ans += cnt2;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("F.inp", "r", stdin);
    // freopen("F.out", "w", stdout);
int q; cin >> q; while (q--){
    cycleLen.clear();
    cin >> n;
    ForE(i, 1, n){
        cin >> p[i];
        ck[i] = 0;
    }
    ForE(i, 1, n){
        if (!ck[i]){
            int len = 1, x = i; ck[x] = 1;
            while (p[x] != i){
                len++;
                x = p[x];
                ck[x] = 1;
            }
            cycleLen.push_back(len);
        }
    }
    sort(bend(cycleLen));
    if (n == 1){
        cout << 1 << ' ' << 0 << endl;
        continue;
    }
    if (n == 2){
        if (p[1] == 1){
            cout << 2 << ' ' << 1 << endl;
        }
        else{
            cout << 2 << ' ' << 0 << endl;
        }
        continue;
    }
    if (n % 3 == 0){
        cout << binpow(3, n / 3) << ' ';
        int ans = 0, cnt1 = 0, cnt2 = 0, tmp;
        Fora(&len, cycleLen){
            ans += len / 3;
            if (len % 3 == 0){
                ans--;
            }
            else if (len % 3 == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        ans += cal(cnt1, cnt2);
        cout << ans << endl;
    }
    else if (n % 3 == 1){
        cout << 4ll * binpow(3, n / 3 - 1) % mod << ' ';
        int ans = mod, cnt1 = 0, cnt2 = 0, tmp = 0; bool ck1 = 0;
        Fora(&len, cycleLen){
            if (len >= 3) ck1 = 1;
            tmp += len / 3;
            if (len % 3 == 0){
                tmp--;
            }
            else if (len % 3 == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        // cout << tmp << ' ' << cnt1 << ' ' << cnt2 << endl;
        // make 4
        Fora(&len, cycleLen){
            if (len >= 4){ // choose 4 in len
                int prevcnt1 = cnt1, prevcnt2 = cnt2, prevtmp = tmp;
                tmp -= len / 3;
                if (len % 3 == 0){
                    tmp++;
                }
                else if (len % 3 == 1){
                    cnt1--;
                }
                else{
                    cnt2--;
                }
                tmp += (len - 4) / 3;
                if ((len - 4) % 3 == 0){
                    tmp--;
                }
                else if ((len - 4) % 3 == 1){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
                // cout << tmp << ' ' << cnt1 << ' ' << cnt2 << endl;
                ans = min(ans, tmp + 1 + cal(cnt1, cnt2));
                cnt1 = prevcnt1; cnt2 = prevcnt2; tmp = prevtmp;
            }
        }
        // cout << ans << endl;
        if (cnt1 && ck1){
            ans = min(ans, tmp + 1 + cal(cnt1 - 1, cnt2));
        }
        if (cnt1 >= 4){ // 4 of 1
            ans = min(ans, tmp + 2 + cal(cnt1 - 4, cnt2));
        }
        if (cnt1 >= 2 && cnt2 >= 1){ // 2 of 1, 1 of 2
            ans = min(ans, tmp + 1 + cal(cnt1 - 2, cnt2 - 1));
        }
        if (cnt2 >= 2){ // 2 of 2
            ans = min(ans, tmp + cal(cnt1, cnt2 - 2));
        }
        cout << ans << endl;
    }
    else{
        cout << 2ll * binpow(3, n / 3) % mod << ' ';
        int ans = mod, cnt1 = 0, cnt2 = 0, tmp = 0;
        Fora(&len, cycleLen){
            tmp += len / 3;
            if (len % 3 == 0){
                tmp--;
            }
            else if (len % 3 == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        if (cnt1 >= 2){
            ans = min(ans, tmp + 1 + cal(cnt1 - 2, cnt2));
        }
        if (cnt2 >= 1){
            ans = min(ans, tmp + cal(cnt1, cnt2 - 1));
        }
        cout << ans << endl;
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