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
int top[2000001];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        top[x] = x;
    }
    top[0] = -1;
    for (int i = 1; i <= 2000000; i++)
        top[i] = max (top[i], top[i - 1]);
    int ans = 0;
    for (int i = 1000000; i > 0 && i > ans; i--)
        if (top[i] == i) {
            for (int j = i; j + i <= 2000000; j += i) {
                int cur = top[j + i - 1];
                if (cur != -1 && cur > j)
                    ans = max (ans, cur - j);
            }
        }
    printf ("%d\n", ans);
    return 0;
}