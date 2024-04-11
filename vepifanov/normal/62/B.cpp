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
string s[100001];
vi v[26];
int f[26];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> s[i];
    for (int j = 0; j < 26; j++) {
        v[j].clear ();
        f[j] = 0;
    }   
    for (int j = 0; j < sz (s[0]); j++) v[s[0][j] - 'a'].pb (j);
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = 0; j < 26; j++) f[j] = 0;
        for (int j = 0; j < sz (s[i]); j++) {
            int x = s[i][j] - 'a';
            if (v[x].empty ()) cur += sz (s[i]); else {
                while (f[x] + 1 < sz (v[x]) && v[x][f[x] + 1] <= j) f[x]++;
                int tmp = abs (v[x][f[x]] - j);
                if (f[x] + 1 < sz (v[x])) tmp = min (tmp, abs (v[x][f[x] + 1] - j));
                cur += tmp;
            }
        }
        printf ("%I64d\n", cur);
    }
        
    return 0;
}