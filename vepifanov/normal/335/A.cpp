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
string s;
int cnt[26];

int main () {
    cin >> s >> n;
    for (int i = 0; i < sz (s); i++)
        cnt[s[i] - 'a']++;
    for (int k = 1; k <= sz (s); k++) {
        int cur = 0;
        for (int j = 0; j < 26; j++) cur += (cnt[j] + k - 1) / k;
        if (cur <= n) {
            printf ("%d\n", k);
            for (int j = 0; j < 26; j++) printf ("%s",  string ((cnt[j] + k - 1) / k, j + 'a').c_str ());
            printf ("%s\n", string (n - cur, 'a').c_str ());
            re 0;
        }
    }
    printf ("-1\n");
    return 0;
}