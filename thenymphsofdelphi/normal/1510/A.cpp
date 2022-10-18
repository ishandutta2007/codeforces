#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

#define INPUT 0
#define EXPR 1
#define TERM 2
#define ATOM 3

const int N = 1e2 + 5, M = 5e3 + 5;

string s;

int cktype[4][N][N];

bool calcktype(int type, int l, int r){
    if (cktype[type][l][r] != -1){
        return cktype[type][l][r];
    }
    if (type == INPUT){
        return (cktype[type][l][r] = calcktype(EXPR, l, r));
    }
    if (type == EXPR){
        if (calcktype(TERM, l, r)){
            return (cktype[type][l][r] = 1);
        }
        ForE(i, l + 1, r - 1){
            if (s[i] == '|' and calcktype(TERM, l, i - 1) and calcktype(EXPR, i + 1, r)){
                return (cktype[type][l][r] = 1);
            }
        }
        return (cktype[type][l][r] = 0);
    }
    if (type == TERM){
        if (calcktype(ATOM, l, r)){
            return (cktype[type][l][r] = 1);
        }
        For(i, l, r){
            if (calcktype(ATOM, l, i) and calcktype(TERM, i + 1, r)){
                return (cktype[type][l][r] = 1);
            }
        }
        For(i, l, r){
            if (calcktype(TERM, l, i) and calcktype(ATOM, i + 1, r)){
                return (cktype[type][l][r] = 1);
            }
        }
        return (cktype[type][l][r] = 0);
    }
    if (type == ATOM){
        if (l == r and isupper(s[l])){
            return (cktype[type][l][r] = 1);
        }
        if (r - l + 1 >= 3 and s[l] == '(' and s[r] == ')' and calcktype(EXPR, l + 1, r - 1)){
            return (cktype[type][l][r] = 1);
        }
        if (r - l + 1 >= 2 and s[r] == '+' and calcktype(ATOM, l, r - 1)){
            return (cktype[type][l][r] = 1);
        }
        if (r - l + 1 >= 2 and s[r] == '?' and calcktype(ATOM, l, r - 1)){
            return (cktype[type][l][r] = 1);
        }
        if (r - l + 1 >= 2 and s[r] == '*' and calcktype(ATOM, l, r - 1)){
            return (cktype[type][l][r] = 1);
        }
        return (cktype[type][l][r] = 0);
    }
    assert(0);
    return 0;
}

char a[M][M];

pii filla(int type, int l, int r, int x, int y){
    // cout << "A " << type << ' ' << l << ' ' << r << ' ' << x << ' ' << y << endl;
    pii ans = make_pair(0, 0);
    if (type == INPUT){
        pii tans = filla(EXPR, l, r, x, y + 3);
        ans.fi = tans.fi; ans.se = tans.se + 6;
        a[x + 1][y] = 'S'; a[x + 1][y + 1] = '-'; a[x + 1][y + 2] = '>';
        a[x + 1][y + tans.se + 3] = '-'; a[x + 1][y + tans.se + 4] = '>'; a[x + 1][y + tans.se + 5] = 'F';
        return ans;
    }
    if (type == EXPR){
        if (cktype[TERM][l][r]){
            return filla(TERM, l, r, x, y);
        }
        int tl = l;
        vpii rangeterms, tansrangeterms;
        ForE(i, l + 1, r - 1){
            if (s[i] == '|' and cktype[TERM][tl][i - 1] and cktype[EXPR][i + 1][r]){
                rangeterms.emplace_back(tl, i - 1);
                tl = i + 1;
            }
        }
        rangeterms.emplace_back(tl, r);
        int tx = x;
        Fora(&range, rangeterms){
            pii tans = filla(TERM, range.fi, range.se, tx, y + 3);
            tansrangeterms.emplace_back(tans);
            tx += tans.fi + 1;
            ans.fi += tans.fi + 1; ans.se = max(ans.se, tans.se);
        }
        ans.fi--; ans.se += 6;
        tx = x;
        For(i, 0, isz(tansrangeterms)){
            pii tans = tansrangeterms[i];
            a[tx + 1][y] = '+'; a[tx + 1][y + 1] = '-'; a[tx + 1][y + 2] = '>';
            ForE(j, y + 3 + tans.se, y + ans.se - 4){
                a[tx + 1][j] = '-';
            }
            a[tx + 1][y + ans.se - 3] = '-'; a[tx + 1][y + ans.se - 2] = '>'; a[tx + 1][y + ans.se - 1] = '+';
            if (i != isz(tansrangeterms) - 1){
                ForE(j, tx + 2, tx + tans.fi + 1){
                    a[j][y] = '|'; a[j][y + ans.se - 1] = '|';
                }
            }
            tx += tans.fi + 1;
        }
        return ans;
    }
    if (type == TERM){
        bool ck = 1;
        ForE(i, l, r){
            if (!isupper(s[i])){
                ck = 0;
                break;
            }
        }
        if (ck){
            ans.fi = 3; ans.se = r - l + 5;
            ForE(i, x, x + 2){
                ForE(j, y, y + r - l + 4){
                    if (j == y or j == y + r - l + 4){
                        a[i][j] = '+';
                    }
                    else if (i == x or i == x + 2){
                        a[i][j] = '-';
                    }
                    else if (j >= y + 2 and j <= y + r - l + 2){
                        a[i][j] = s[l + j - y - 2];
                    }
                }
            }
            return ans;
        }
        int tl = l;
        vpii rangeatoms, tansrangeatoms; vector <bool> isTERM;
        For(i, l, r){
            if (cktype[ATOM][tl][i] and cktype[TERM][i + 1][r]){
                rangeatoms.emplace_back(tl, i);
                tl = i + 1;
            }
        }
        rangeatoms.emplace_back(tl, r);
        vpii rangeatoms2; tl = -1;
        Fora(&range, rangeatoms){
            if (range.fi == range.se){
                if (tl == -1){
                    tl = range.fi;
                }
            }
            else{
                if (tl != -1){
                    rangeatoms2.emplace_back(tl, range.fi - 1);
                    isTERM.emplace_back(1);
                    tl = -1;
                }
                rangeatoms2.emplace_back(range);
                isTERM.emplace_back(0);
            }
        }
        if (tl != -1){
            rangeatoms2.emplace_back(tl, r);
            isTERM.emplace_back(1);
        }
        rangeatoms = rangeatoms2;
        int ty = y;
        For(i, 0, isz(rangeatoms)){
            pii range = rangeatoms[i], tans;
            if (isTERM[i]){
                tans = filla(TERM, range.fi, range.se, x, ty);
            }
            else{
                tans = filla(ATOM, range.fi, range.se, x, ty);
            }
            ans.fi = max(ans.fi, tans.fi); ans.se += tans.se;
            tansrangeatoms.emplace_back(tans);
            ty += tans.se;
            if (i != isz(rangeatoms) - 1){
                ans.se += 2;
                a[x + 1][ty] = '-'; a[x + 1][ty + 1] = '>';
                ty += 2;
            }
        }
        return ans;
    }
    if (type == ATOM){
        if (l == r and isupper(s[l])){
            return filla(TERM, l, r, x, y);
        }
        if (r - l + 1 >= 3 and s[l] == '(' and s[r] == ')' and cktype[EXPR][l + 1][r - 1]){
            return filla(EXPR, l + 1, r - 1, x, y);
        }
        if (r - l + 1 >= 2 and s[r] == '+' and cktype[ATOM][l][r - 1]){
            pii tans = filla(ATOM, l, r - 1, x, y + 3);
            ans.fi = tans.fi + 2; ans.se = tans.se + 6;
            a[x + 1][y] = '+'; a[x + 1][y + 1] = '-'; a[x + 1][y + 2] = '>';
            a[x + 1][y + tans.se + 3] = '-'; a[x + 1][y + tans.se + 4] = '>'; a[x + 1][y + tans.se + 5] = '+';
            ForE(i, x + 2, x + tans.fi){
                a[i][y] = '|'; a[i][y + tans.se + 5] = '|';
            }
            a[x + tans.fi + 1][y] = '+'; a[x + tans.fi + 1][y + 1] = '<'; a[x + tans.fi + 1][y + tans.se + 5] = '+';
            ForE(i, y + 2, y + tans.se + 4){
                a[x + tans.fi + 1][i] = '-';
            }
            return ans;
        }
        if (r - l + 1 >= 2 and s[r] == '?' and cktype[ATOM][l][r - 1]){
            pii tans = filla(ATOM, l, r - 1, x + 3, y + 3);
            ans.fi = tans.fi + 3; ans.se = tans.se + 6;
            a[x + 1][y] = '+'; a[x + 1][y + tans.se + 4] = '>'; a[x + 1][y + tans.se + 5] = '+';
            ForE(i, y + 1, y + tans.se + 3){
                a[x + 1][i] = '-';
            }
            ForE(i, x + 2, x + 3){
                a[i][y] = '|'; a[i][y + tans.se + 5] = '|';
            }
            a[x + 4][y] = '+'; a[x + 4][y + 1] = '-'; a[x + 4][y + 2] = '>';
            a[x + 4][y + tans.se + 3] = '-'; a[x + 4][y + tans.se + 4] = '>'; a[x + 4][y + tans.se + 5] = '+';
            return ans;
        }
        if (r - l + 1 >= 2 and s[r] == '*' and cktype[ATOM][l][r - 1]){
            pii tans = filla(ATOM, l, r - 1, x + 3, y + 3);
            ans.fi = tans.fi + 5; ans.se = tans.se + 6;
            a[x + 1][y] = '+'; a[x + 1][y + tans.se + 4] = '>'; a[x + 1][y + tans.se + 5] = '+';
            ForE(i, y + 1, y + tans.se + 3){
                a[x + 1][i] = '-';
            }
            ForE(i, x + 2, x + 3){
                a[i][y] = '|'; a[i][y + tans.se + 5] = '|';
            }
            a[x + 4][y] = '+'; a[x + 4][y + 1] = '-'; a[x + 4][y + 2] = '>';
            a[x + 4][y + tans.se + 3] = '-'; a[x + 4][y + tans.se + 4] = '>'; a[x + 4][y + tans.se + 5] = '+';
            ForE(i, x + 5, x + tans.fi + 3){
                a[i][y] = '|'; a[i][y + tans.se + 5] = '|';
            }
            a[x + tans.fi + 4][y] = '+'; a[x + tans.fi + 4][y + 1] = '<'; a[x + tans.fi + 4][y + tans.se + 5] = '+';
            ForE(i, y + 2, y + tans.se + 4){
                a[x + tans.fi + 4][i] = '-';
            }
            return ans;
        }
    }
    assert(0);
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s;
    memset(cktype, -1, sizeof(cktype));
    For(type, 0, 4){
        For(l, 0, isz(s)){
            For(r, l, isz(s)){
                calcktype(type, l, r);
            }
        }
    }
    assert(cktype[INPUT][0][isz(s) - 1]);
    For(i, 0, M){
        For(j, 0, M){
            a[i][j] = ' ';
        }
    }
    pii cac = filla(INPUT, 0, isz(s) - 1, 1, 1);
    cout << cac.fi << ' ' << cac.se << endl;
    ForE(i, 1, cac.fi){
        ForE(j, 1, cac.se){
            cout << a[i][j];
        } cout << endl;
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/