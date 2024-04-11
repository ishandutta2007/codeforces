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

const char w[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

int n;
int m;

int main() {
    scanf ("%d", &n);
    m = n % 7;
    for (int i = 0; i < 4; i++) printf ("%c", w[i]);
    for (int i = 4; i < m; i++) printf ("%c", w[i]);
    for (int i = 0; i < m && i < 4; i++) printf ("%c", w[i]);
    for (int i = 4; i < n - m; i++) printf ("%c", w[i % 7]);
    return 0;
}