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
string s;

int main () {
    cin >> s >> m;
    n = sz (s);
    if (n % m != 0) {
        cout << "NO" << endl;
        re 0;
    }
    int len = n / m;
    for (int i = 0; i < m; i++) {
        int a = i * len;
        int b = (i + 1) * len - 1;
        int ok = 1;
        while (a < b) {
            ok &= int (s[a] == s[b]);
            a++; b--;
        }
        if (!ok) {
            cout << "NO" << endl;
            re 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}