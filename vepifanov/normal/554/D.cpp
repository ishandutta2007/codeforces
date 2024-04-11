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
ll m;
ll res[51];

int main () {
    cin >> n >> m;
    res[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 2 && j <= i; j++)
            res[i] = min (m, res[i] + res[i - j]);
    for (int i = 0; i < n; )   
        for (int j = 1; j <= 2 && j <= n - i; j++)
            if (res[n - i - j] < m)
                m -= res[n - i - j];
            else
            {
                for (int k = 0; k < j; k++)
                    printf ("%d ", (k + j - 1) % j + i + 1);
                i += j;
                break;
            }   
    printf ("\n");
    return 0;
}