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
int r;
ii v[100000];
string s[100000];

int out (int x) {
    if (v[x].fi != -1) {
        printf ("pair<");
        out (v[x].fi);
        printf (",");
        out (v[x].se);
        printf (">");
    } else printf ("int");
    re 0;
}

int go () {
    if (m >= n) re -1;
    int tmp = int (s[m] == "pair");
    m++;
    if (tmp) {
        int a = go ();
        int b = go ();
        if (a == -1 || b == -1) re -1;
        v[r] = mp (a, b);
    } else v[r] = mp (-1, -1);
    r++;
    re r - 1;
}


int main () {
    cin >> n;
    n = 0;
    while (cin >> s[n]) n++;
    m = 0;
    int tmp = go ();
    if (tmp == -1 || m < n) printf ("Error occurred"); else out (tmp);
    printf ("\n");
    return 0;
}