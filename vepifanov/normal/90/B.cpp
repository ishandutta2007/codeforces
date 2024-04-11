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
char w[101][101];

int main() {
    scanf ("%d%d", &n, &m); 
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int ok = 1;
            for (int p = 0; p < m; p++)
                if (p != j && w[i][j] == w[i][p])
                    ok = 0;
            for (int q = 0; q < n; q++)
                if (q != i && w[i][j] == w[q][j])
                    ok = 0;
            if (ok) printf ("%c", w[i][j]);
        }
    printf ("\n");
    return 0;
}