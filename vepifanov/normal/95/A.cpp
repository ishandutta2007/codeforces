#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
char l, r;
string s[100], t;

int bad[101];

int eq (string a, string b) {
    for (int i = 0; i < sz (a); i++)
        if (a[i] != b[i] && abs (a[i] - b[i]) != abs ('a' - 'A'))
            re 0;
    re 1;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> t;
    cin >> l;
    if (l == 'a') r = 'b'; else r = 'a';
    for (int i = 0; i < sz (t); i++)
        for (int j = 0; j < n; j++)
            if (i + sz (s[j]) <= sz (t) && eq (t.substr (i, sz (s[j])), s[j]))
                for (int k = 0; k < sz (s[j]); k++)
                    bad[k + i] = 1;
    for (int i = 0; i < sz (t); i++)
        if (bad[i])
            if (t[i] == l) t[i] = r; else
            if (t[i] == l - 'a' + 'A') t[i] = r - 'a' + 'A'; else
            if (t[i] >= 'a' && t[i] <= 'z')
                t[i] = l;
            else
                t[i] = l - 'a' + 'A';   
    cout << t << endl;
    return 0;
}