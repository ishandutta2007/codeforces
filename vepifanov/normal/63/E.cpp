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

int n;
int m;
vi v;

int add (int a, int b, int c, int d, int e) {
    int x[5];
    x[0] = a; x[1] = b; x[2] = c; x[3] = d; x[4] = e;
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            if (x[j] != -1) {
                int cur = 0;
                for (int k = i; k <= j; k++)
                    cur |= 1 << x[k];
                v.pb (cur);
            }
    re 0;
}

int was[1 << 19], res[1 << 19];

int go (int mask) {
    if (mask == 0) re 0;
    if (was[mask]) re res[mask];
    was[mask] = 1;
    res[mask] = 0;
    for (int i = 0; i < sz (v); i++)
        if ((mask & v[i]) == v[i] && (!go (mask - v[i]))) {
            res[mask] = 1;
            break;
        }   
    re res[mask]; 
}

int main() {
    add (0, 1, 2, -1, -1);
    add (3, 4, 5, 6, -1);
    add (7, 8, 9, 10, 11);
    add (12, 13, 14, 15, -1);
    add (16, 17, 18, -1, -1);
    add (0, 3, 7, -1, -1);
    add (1, 4, 8, 12, -1);
    add (2, 5, 9, 13, 16);
    add (6, 10, 14, 17, -1);
    add (11, 15, 18, -1, -1);
    add (2, 6, 11, -1, -1);
    add (1, 5, 10, 15, -1);
    add (0, 4, 9, 14, 18);
    add (3, 8, 13, 17, -1);
    add (7, 12, 16, -1, -1);
    int mask = 0;
    for (int i = 0; i < 19; i++) {
        string s;
        cin >> s;
        if (s[0] == 'O') mask |= 1 << i;
    }
    if (go (mask)) printf ("Karlsson\n"); else printf ("Lillebror\n");
    return 0;
}