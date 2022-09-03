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

int n, a, b;
string s;

int main() {
    cin >> n >> a >> b;
    cin >> s;
    int m = sz (s);
    if (m >= n * a && m <= n * b)  {
        for (int i = 0; i < n; i++)
            for (int j = a; j <= b; j++)
                if ((m - j) >= (n - i - 1) * a && (m - j) <= (n - i - 1) * b) {
                    m -= j;
                    cout << s.substr (0, j) << endl;
                    s.erase (0, j);
                    break;
                }
    } else cout << "No solution" << endl;
    return 0;
}