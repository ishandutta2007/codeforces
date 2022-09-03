#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const string el[100] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl",
            "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se",
            "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
            "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er",
            "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re",  "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", 
            "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};

int n;
int m;
int a[20], b[20];
int was[1 << 17][17], res[1 << 17][17], use[1 << 17][17];
int sum[1 << 17], forb[1 << 17];

int get (string s) {
    for (int i = 0; i < 100; i++)
        if (el[i] == s)
            re i + 1;
    re 0;
}

int go (int mask, int i) {
    if (mask == 0) re 1;
    if (was[mask][i]) re res[mask][i];
    was[mask][i] = 1;
    res[mask][i] = 0;
    for (int nmask = mask; nmask > 0; nmask = (nmask - 1) & mask)
        if (sum[nmask] == b[i] && !forb[mask - nmask] && go (mask - nmask, i + 1)) {
            use[mask][i] = nmask;
            re res[mask][i] = 1;
        }
    re 0;   
}

int out (int mask, int j) {
    if (mask == 0) re 0;
    int nmask = use[mask][j], f = 0;
    for (int i = 0; i < n; i++) 
        if ((nmask >> i) & 1) {
            if (f) cout << "+";
            cout << el[a[i] - 1];
            f = 1;
        }
    cout << "->" << el[b[j] - 1] << endl;
    out (mask - nmask, j + 1);
    re 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = get (s);
    }   
    sort (a, a + n);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        b[i] = get (s);
    }
    sort (b, b + m);
    for (int i = 0; i < (1 << n); i++) {
        sum[i] = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                sum[i] += a[j];
        forb[i] = 0;
        for (int j = 1; j < n; j++)
            if (a[j - 1] == a[j] && ((i >> (j - 1)) & 1) == 0 && ((i >> j) & 1) == 1)
                forb[i] = 1;
    }
    if (go ((1 << n) - 1, 0)) {
        cout << "YES" << endl;
        out ((1 << n) - 1, 0);
    } else cout << "NO" << endl;
    return 0;
}