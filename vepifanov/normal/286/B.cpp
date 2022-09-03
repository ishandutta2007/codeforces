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
int p[1000000];
int q[2000000];
int a[1000000];
int b[1000000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        q[i] = i;
    }   
    for (int i = 2; i <= n; i++) {
        int o = 0;
        for (int j = 0; j < n; j += i) {
            int l = min (i, n - j);
            int k = j + i - 2;
            a[o] = q[k];
            b[o] = k + l;
            o++;
        }
        for (int j = 0; j < o; j++) {
            p[a[j]] = b[j];
            q[b[j]] = a[j];
        }
    }
    for (int j = 0; j < n; j++) printf ("%d ", q[n - 1 + j] + 1);
    printf ("\n");
    return 0;
}