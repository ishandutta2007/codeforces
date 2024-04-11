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
string s;

int good (int h) {
    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'L' && x - 1 > -h)
            x--;
        else
        if (s[i] == 'R')
            x++;    
        y = max (y, x);
    }
    re int (x == y);
}

int main () {
    cin >> s;
    n = sz (s);
    if (s[sz (s) - 1] == 'L')
        for (int i = 0; i < sz (s); i++)
            if (s[i] == 'L')
                s[i] = 'R';
            else
                s[i] = 'L'; 
    if (good (1e9)) printf ("1\n"); else {
        int l = 0, r = 1e9;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (good (s)) l = s; else r = s;
        }
        printf ("%d\n", l);
    }
    return 0;
}