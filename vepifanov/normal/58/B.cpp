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
int res[1000], prev[1000];
vi v;

int out (int x) {
    printf ("%d ", v[x]);
    if (x != 0) out (prev[x]); else printf ("\n");
    re 0;
}

int main() {
    scanf ("%d", &n);   
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            v.pb (i);
    res[0] = 1;
    for (int i = 1; i < sz (v); i++) {
        res[i] = 0;
        for (int j = 0; j < i; j++)
            if (v[i] % v[j] == 0 && res[i] < res[j] + 1) {
                res[i] = res[j] + 1;
                prev[i] = j;
            }   
    }
    out (sz (v) - 1);
    return 0;
}