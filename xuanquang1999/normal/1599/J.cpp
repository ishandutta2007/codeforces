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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3 + 5, M = 1e6 + 5;

int n;
int a[N];

vi vpos[2];

int pos[M];

int m, m2;
int b[30];
int pw3[20];

struct hash_pair{
    int operator()(const pii& a) const {
        return a.fi * 64 + a.se;
    }
};

unordered_map <pii, int, hash_pair> mpp;

int ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ForE(i, 2, n){
        if (a[i] == a[i - 1]){
            cout << "YES" << endl;
            ForE(j, 1, n){
                if (j == i){
                    cout << 0 << ' ';
                }
                else{
                    cout << a[j] << ' ';
                }
            }
            return 0;
        }
    }
    if (n == 2){
        cout << "NO" << endl;
        return 0;
    }
    ForE(i, 1, n){
        vpos[a[i] % 2].emplace_back(i);
    }
    if (n == 3){
        if (isz(vpos[1]) == 1 or isz(vpos[1]) == 3){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        int sum = (a[1] + a[2] + a[3]) / 2;
        cout << sum - a[1] << ' ' << sum - a[2] << ' ' << sum - a[3] << endl;
        return 0;
    }
    if (isz(vpos[0]) >= 1 and isz(vpos[1]) >= 2){
        cout << "YES" << endl;
        int sum = (a[vpos[0][0]] + a[vpos[1][0]] + a[vpos[1][1]]) / 2;
        ForE(i, 1, n){
            if (i == vpos[0][0]){
                cout << sum - a[vpos[0][0]] << ' ';
            }
            else if (i == vpos[1][0]){
                cout << sum - a[vpos[1][0]] << ' ';
            }
            else if (i == vpos[1][1]){
                cout << sum - a[vpos[1][1]] << ' ';
            }
            else{
                cout << a[i] - (sum - a[vpos[0][0]]) << ' ';
            }
        } cout << endl;
        return 0;
    }
    if (isz(vpos[0]) >= 3){
        cout << "YES" << endl;
        int sum = (a[vpos[0][0]] + a[vpos[0][1]] + a[vpos[0][2]]) / 2;
        ForE(i, 1, n){
            if (i == vpos[0][0]){
                cout << sum - a[vpos[0][0]] << ' ';
            }
            else if (i == vpos[0][1]){
                cout << sum - a[vpos[0][1]] << ' ';
            }
            else if (i == vpos[0][2]){
                cout << sum - a[vpos[0][2]] << ' ';
            }
            else{
                cout << a[i] - (sum - a[vpos[0][0]]) << ' ';
            }
        } cout << endl;
        return 0;
    }

    shuffle(a + 1, a + n + 1, rando);
    ForE(i, 1, n){
        pos[a[i]] = i;
    }
    m = min(n, 26);
    m2 = m / 2;
    For(i, 0, m){
        b[i] = a[i + 1];
    }
    pw3[0] = 1;
    For(i, 1, 20){
        pw3[i] = pw3[i - 1] * 3;
    }
    
    For(msk1, 0, pw3[m2]){
        int tmsk = msk1, sum = 0, cnt = 0;
        For(i, 0, m2){
            div_t dtmsk = div(tmsk, 3);
            tmsk = dtmsk.quot;
            if (dtmsk.rem == 1){
                sum += b[i];
                cnt++;
            }
            else if (dtmsk.rem == 2){
                sum -= b[i];
                cnt--;
            }
        }
        mpp[make_pair(sum, cnt)] = msk1;
    }
    For(msk2, 0, pw3[m - m2]){
        int tmsk = msk2, sum = 0, cnt = 0;
        For(i, m2, m){
            div_t dtmsk = div(tmsk, 3);
            tmsk = dtmsk.quot;
            if (dtmsk.rem == 1){
                sum += b[i];
                cnt++;
            }
            else if (dtmsk.rem == 2){
                sum -= b[i];
                cnt--;
            }
        }
        if (mpp.count(make_pair(-sum, -cnt))){
            int msk1 = mpp[make_pair(-sum, -cnt)];
            if (msk1 == 0 and msk2 == 0){
                continue;
            }
            vi vvall, vvalr;
            tmsk = msk1;
            For(i, 0, m2){
                div_t dtmsk = div(tmsk, 3);
                tmsk = dtmsk.quot;
                if (dtmsk.rem == 1){
                    vvall.emplace_back(b[i]);
                }
                else if (dtmsk.rem == 2){
                    vvalr.emplace_back(b[i]);
                }
            }
            tmsk = msk2;
            For(i, m2, m){
                div_t dtmsk = div(tmsk, 3);
                tmsk = dtmsk.quot;
                if (dtmsk.rem == 1){
                    vvall.emplace_back(b[i]);
                }
                else if (dtmsk.rem == 2){
                    vvalr.emplace_back(b[i]);
                }
            }
            vi vval;
            For(i, 0, isz(vvall)){
                vval.emplace_back(vvall[i]);
                vval.emplace_back(vvalr[i]);
            }
            ans[pos[vval[0]]] = 0;
            For(i, 1, isz(vval)){
                ans[pos[vval[i]]] = vval[i - 1] - ans[pos[vval[i - 1]]];
            }
            cout << "YES" << endl;
            ForE(i, 1, n){
                bool ck = 1;
                Fora(val, vval){
                    if (a[i] == val){
                        ck = 0;
                        break;
                    }
                }
                if (ck){
                    ans[i] = a[i] - ans[pos[vval[0]]]; 
                }
                cout << ans[i] << ' ';
            } cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
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