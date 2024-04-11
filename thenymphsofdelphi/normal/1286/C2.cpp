#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 1e2 + 5;

vector <string> ask(int l, int r){ // who asked
    int len = (r - l + 1) * (r - l + 2) / 2;
    cout << "? " << l << ' ' << r << endl;
    vector <string> vans;
    while (len--){
        string s; cin >> s;
        sort(bend(s));
        vans.emplace_back(s);
    }
    sort(bend(vans), [&](const string& lhs, const string& rhs){
        if (isz(lhs) != isz(rhs)){
            return isz(lhs) < isz(rhs);
        }
        return lhs < rhs;
    });
    return vans;
}

void answer(string s){
    cout << "! " << s << endl;
    exit(0);
}

int n;

string s;

int m;
vector <string> a, b, c; // [1, n], [1, m], [1, m - 1]

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;

    s.assign(n, ' ');
    if (n <= 3){
        For(i, 0, n){
            s[i] = ask(i + 1, i + 1)[0][0];
        }
        answer(s);
    }
    m = (n + 1) / 2;
    a = ask(1, n);
    b = ask(1, m);
    c = ask(1, m - 1);
    {
        int i = 0, j = 0, idx = m;
        int cnt[26]; memset(cnt, 0, sizeof(cnt));
        while (i < isz(b)){
            if (j == isz(c) or b[i] != c[j]){
                int tcnt[26]; memset(tcnt, 0, sizeof(tcnt));
                Fora(cac, b[i]){
                    tcnt[cac - 'a']++;
                }
                For(cac, 0, 26){
                    if (cnt[cac] != tcnt[cac]){
                        s[--idx] = (char)(cac + 'a');
                        cnt[cac] = tcnt[cac];
                        break;
                    }
                }
                i++;
            }
            else{
                i++; j++;
            }
        }
    }
    {
        int cnt[26], cntall[26], idxa = isz(a) - 1;
        memset(cntall, 0, sizeof(cntall));
        Fora(cac, a[idxa]){
            cntall[cac - 'a']++;
        }
        idxa--;
        FordE(idx, n, m + 1){
            memset(cnt, 0, sizeof(cnt));
            int len = idx - 1;
            while (idxa >= 0 and isz(a[idxa]) == len){
                For(cac, 0, 26){
                    cnt[cac] += cntall[cac];
                }
                Fora(cac, a[idxa]){
                    cnt[cac - 'a']--;
                }
                idxa--;
            }
            ForE(i, 1, n - idx + 1){
                cnt[s[i - 1] - 'a'] -= n - idx + 2 - i;
                if (i != n - idx + 1){
                    cnt[s[n - i] - 'a'] -= n - idx + 2 - i;
                }
            }
            For(cac, 0, 26){
                if (cnt[cac]){
                    s[idx - 1] = (char)(cac + 'a');
                    break;
                }
            }
        }
    }
    answer(s);
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