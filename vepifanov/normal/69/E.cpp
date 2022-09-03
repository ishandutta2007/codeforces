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

int n, k;
int m;
int x[100000];
map<int, int> cnt;
set<int> all;

int main() {
    scanf ("%d%d", &n, &k); 
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        x[i] = -x[i];
        cnt[x[i]]++;
        if (cnt[x[i]] == 1) all.insert (x[i]); else
        if (cnt[x[i]] == 2) all.erase (x[i]);
        if (i - k >= 0) {
            cnt[x[i - k]]--;
            if (cnt[x[i - k]] == 1) all.insert (x[i - k]); else
            if (cnt[x[i - k]] == 0) all.erase (x[i - k]);
        }
        if (i >= k - 1) {
            if (all.empty ()) printf ("Nothing\n"); else printf ("%d\n", -(*all.begin ()));
        }
    }
    printf ("\n");
    return 0;
}