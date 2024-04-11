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
int m, r = 0;
int z[10000001];
int a[1000001];
int p[1000001];
int l;
int ans = 0;


int getp (int x) {
    if (p[x] != x) p[x] = getp (p[x]);
    re p[x];
}

int un (int a, int b) {
    int pa = getp (a);
    int pb = getp (b);
    if (pa != pb) {
        ans--;
        if (rand () & 1)
            p[pa] = pb;
        else
            p[pb] = pa;
    }
    re 0;   
}

int gcd (int a, int b) {
    if (!a) re b;
    re gcd (b % a, a);
}

int main() {
    scanf ("%d", &n);
    memset (z, -1, sizeof (z));
    for (int i = 0; i < n; i++) {
        p[i] = i;
        scanf ("%d", &a[i]);
        z[a[i]] = i;
    }
    ans = n;
    int sum = 0;
    for (int x = 2; x <= 4000; x++)
        for (int y = 1; y < x; y++)
            if (((x ^ y) & 1) && gcd (x, y) == 1) {
                ll a = (ll)x * x - (ll)y * y;
                ll b = (ll)2 * x * y;
                ll c = (ll)x * x + (ll)y * y;
                if (a > b) swap (a, b);
                if (b > c) swap (b, c);
                if (a > b) swap (a, b);
                if (b <= 10000000 && z[a] != -1 && z[b] != -1) un (z[a], z[b]);
                if (c <= 10000000 && z[a] != -1 && z[c] != -1) un (z[a], z[c]);
                if (c <= 10000000 && z[c] != -1 && z[b] != -1) un (z[c], z[b]);
            }
    cerr << sum << endl;
    printf ("%d\n", ans);

    return 0;
}