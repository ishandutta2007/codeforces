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
int m, a, b;
string s, w;

string calc (string s) {
    int a = ::a, b = ::b;
    for (int i = 0; i < n && a; i++)
        if (s[i] == '1') {
            s[i] = '?';
            a--;
        }   
    for (int i = 0; i < n && b; i++)
        if (s[i] == '0') {
            s[i] = '?';
            b--;
        }   
    string w = "";
    for (int i = 0; i < n; i++)
        if (s[i] != '?')
            w += s[i];
    re w.substr (0, 2);
}

int main () {
    cin >> s;
    n = sz (s);
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            c0++;
        else
        if (s[i] == '1')    
            c1++;
    a = (n - 1) / 2;
    b = (n - 2) / 2;
    w = s;
    for (int i = 0; i < n; i++)
        if (w[i] == '?')
            w[i] = '0';
        if (calc (w) == "00") printf ("00\n");
    w = s;
    int r = max (0, (a + 1) - c1);
    for (int i = n - 1; i >= 0; i--)
        if (w[i] == '?')
            if (r > 0) {
                w[i] = '1';
                r--;
            } else w[i] = '0';
    if (calc (w) == "01") printf ("01\n");
    w = s;
    r = max (0, (b + 1) - c0);
    for (int i = n - 1; i >= 0; i--)
        if (w[i] == '?')
            if (r > 0) {
                w[i] = '0';
                r--;
            } else w[i] = '1';
    if (calc (w) == "10") printf ("10\n");
    w = s;
    for (int i = 0; i < n; i++)
        if (w[i] == '?')
            w[i] = '1';
    if (calc (w) == "11") printf ("11\n");
    return 0;
}