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

map<string, int> all;

int main () {
    cin >> s;   
    string ans = "-1";
    int res = -1;
    for (int i = 0; i < sz (s); i++)
        for (int j = 1; i + j <= sz (s); j++) {
            string w = s.substr (i, j);
            int ok = 1;
            for (int k = 0; k < sz (w); k++)
                if (w[k] != '4' && w[k] != '7') {
                    ok = 0;
                    break;
                }
            if (ok) {
                all[w]++;
                if (all[w] > res || all[w] == res && w < ans) {
                    res = all[w];
                    ans = w;
                }
            }
        }   
    cout << ans << endl;
    return 0;
}