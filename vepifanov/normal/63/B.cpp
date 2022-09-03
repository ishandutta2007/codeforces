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
int x[100];
          
int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int ans = 0;
    while (x[0] < m) {
        ans++;
        int last = m;
        for (int i = n - 1; i >= 0; i--)
            if (x[i] < last) {
                last = x[i];
                x[i]++;
            }
    }
    printf ("%d\n", ans);
    return 0;
}