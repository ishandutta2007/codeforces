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

int main () {
    scanf ("%d", &n);
    ii a1, a2, a3;
    a1 = a2 = a3 = mp (0, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x == 0) {
            if (a1.fi == 0) {
                printf ("0\n");
            } else
            if (a2.fi == 0) {
                for (int j = 0; j < a1.se; j++) printf ("pushStack\n");
                printf ("pushStack\n");
                for (int j = a2.se + 1; j < cur; j++) printf ("pushFront\n");
                printf ("1 popStack\n");
            } else
            if (a3.fi == 0) {
                if (a1.se > a2.se) swap (a1, a2);
                for (int j = 0; j < a1.se; j++) printf ("pushStack\n");
                printf ("pushStack\n");
                for (int j = a1.se + 1; j < a2.se; j++) printf ("pushFront\n");
                printf ("pushBack\n");
                for (int j = a2.se + 1; j < cur; j++) printf ("pushFront\n");
                printf ("2 popStack popBack\n");
            } else {
                if (a1.se > a2.se) swap (a1, a2);
                if (a2.se > a3.se) swap (a2, a3);
                if (a1.se > a2.se) swap (a1, a2);
                for (int j = 0; j < a1.se; j++) printf ("pushStack\n");
                printf ("pushStack\n");
                for (int j = a1.se + 1; j < a2.se; j++) printf ("pushFront\n");
                printf ("pushBack\n");
                for (int j = a2.se + 1; j < a3.se; j++) printf ("pushFront\n");
                printf ("pushQueue\n");
                for (int j = a3.se + 1; j < cur; j++) printf ("pushQueue\n");
                printf ("3 popStack popBack popQueue\n");
            }
            cur = 0;
            a1 = a2 = a3 = mp (0, 0);
        } else {
            ii a = mp (x, cur++);
            if (a > a1) {
                a3 = a2;
                a2 = a1;
                a1 = a;
            } else
            if (a > a2) {
                a3 = a2;
                a2 = a;
            } else
            if (a > a3)
                a3 = a;
        }
    }
    for (int i = 0; i < cur; i++) printf ("pushStack\n");
    return 0;
}