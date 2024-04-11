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

int m;
ll x, y, n;

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; } 

int main () {
    cin >> x >> y >> n;
    ll q = x / y;
    x %= y;
    ll A = 0, B = 1, a = 0;
    for (ll b = 1; b <= n; b++) {
        while ((a + 1) * y <= x * b) a++;
        if (abs ((a * y - b * x) * B) < abs ((A * y - B * x) * b) || abs ((a * y - b * x) * B) == abs ((A * y - B * x) * b) && mp (b, a) < mp (B, A)) {
            A = a;
            B = b;
        }
        a++;
        if (abs ((a * y - b * x) * B) < abs ((A * y - B * x) * b) || abs ((a * y - b * x) * B) == abs ((A * y - B * x) * b) && mp (b, a) < mp (B, A)) {
            A = a;
            B = b;
        }
        a--;
    }
    ll d = gcd (A, B);
    cout << (A / d) + q * (B / d) << "/" << B / d << endl;
    return 0;
}