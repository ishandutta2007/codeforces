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
int g[200][200];
int x[200], q[200], was[200];

int main() {
    scanf ("%d", &n);
    memset (g, 0, sizeof (g));
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int l;
        scanf ("%d", &l);
        for (int j = 0; j < l; j++) {
            scanf ("%d", &x[j]); 
            x[j]--;
        }
        if (n == 2) {
            printf ("1 %d\n", x[0] + 1);
            printf ("%d ", l - 1);
            for (int j = 1; j < l; j++)
                printf ("%d ", x[j] + 1);
            printf ("\n");
            re 0;
        }
        for (int j = 0; j < l; j++)
            for (int k = 0; k < l; k++)
                g[x[j]][x[k]]++;
    }
    memset (was, 0, sizeof (was));
    for (int i = 0; i < 200; i++) 
        if (!was[i]) {
            int l = 0;
            for (int j = 0; j < 200; j++)
                if (g[i][j] > 1) {
                    was[j] = 1;
                    q[l++] = j;
                }   
            if (l > 0) {
                printf ("%d ", l);
                for (int j = 0; j < l; j++)
                    printf ("%d ", q[j] + 1);
                printf ("\n");  
            }   
        }
    return 0;
}