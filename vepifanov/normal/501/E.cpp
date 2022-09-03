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
#define prev PREV
                         
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
int cnt[100000];
int x[100000];

int can (int a, int b) {
    memset (cnt, 0, sizeof (cnt));
    for (int i = a; i <= b; i++) cnt[x[i]]++;
    while (a <= b && n - a - 1 > b) {
        if (cnt[x[n - a - 1]] == 0) re 0;
        cnt[x[n - a - 1]]--;
        a++;
    }
    while (a <= b && n - b - 1 < a) {
        if (cnt[x[n - b - 1]] == 0) re 0;
        cnt[x[n - b - 1]]--;
        b--;
    }
    b++;
    while (b < n - b - 1) {
        if (x[b] != x[n - b - 1]) re 0;
        b++;
    }   
    a--;
    while (n - a - 1 < a) {
        if (x[a] != x[n - a - 1]) re 0;
        a--;
    }
    re 1;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]); x[i]--;
        cnt[x[i]] ^= 1;
    }   
    int ok = 0;
    for (int i = 0; i < n; i++) ok += cnt[i];
    if (ok > 1) {
        printf ("0\n");
        re 0;
    }
    int a = 0, b = n - 1;
    while (a < b && x[a] == x[b]) {
        a++;
        b--;
    }
    ll ans = 0;
    if (a >= b) {
        ans = (ll)n * (n + 1) / 2;
    } else {
        int A, B;
        {
            int l = a, r = b;
            while (r - l > 1) {
                int s = (l + r) / 2;
                if (can (a, s)) r = s; else l = s;
            }
            A = r;
        }
        {
            int l = a, r = b;
            while (r - l > 1) {
                int s = (l + r) / 2;
                if (can (s, b)) l = s; else r = s;
            }
            B = l;
        }
        ans = (ll)(a + 1) * (n - A) + (ll)(B + 1) * (n - b) - (ll)(a + 1) * (n - b);
    }
    cout << ans << endl;
    return 0;
}