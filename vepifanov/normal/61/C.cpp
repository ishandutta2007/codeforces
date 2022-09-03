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

const string decim[4][10] = {
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"","M","MM","MMM","","","","","",""}};

int n;
int m;
string sb, sc;
ll a, b, c;

int calc (char c) {
    if (c >= '0' && c <= '9') re c - '0';
    re c - 'A' + 10;
}

char calc2 (int x) {
    if (x < 10) re '0' + x;
    re x - 10 + 'A';
}

ll get (string s, int x) {
    ll tmp = 0;
    for (int i = 0; i < sz (s); i++)
        tmp = tmp * x + calc (s[i]);
    re tmp;
}

int x[100];

int main() {
    cin >> a >> sb >> sc;   
    c = get (sc, a);
    if (sb == "R") {
        int r = 0;
        while (c) {
            x[r] = c % 10;
            c /= 10;
            r++;
        }
        reverse (x, x + r);
        if (r == 0) cout << "0" << endl;
        for (int i = 0; i < r; i++)
            cout << decim[r - i - 1][x[i]];
        cout << endl;   
    } else {
        b = atoi (sb.c_str());
        string s = "";
        if (!c) s += '0';
        while (c) {
            s = calc2 (c % b) + s;
            c /= b;
        }
        cout << s << endl;
    }
    return 0;
}