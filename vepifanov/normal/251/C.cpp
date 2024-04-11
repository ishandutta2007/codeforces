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
ll p[51][400000];
ll a, b;

int gcd (int a, int b) {
    re a ? gcd (b % a, a) : b;
}

int go (ll a, ll b) {
    if (a == b) re 0;
    int c = 1;
    for (int j = 2; j <= m; j++)
        if (b - b % j >= a && b % j > c)
            c = b % j;
    re go (a, b - c) + 1;
}

int main () {
    cin >> b >> a >> m;
    int len = 1;
    for (int i = 1; i <= m; i++) len = len * i / gcd (len, i);
    for (int i = 0; i < len; i++) {
        int k = 1;
        for (int j = 2; j <= m; j++)
            if (i % j > k) 
                k = i % j;
        p[0][i] = k;
    }
    for (int t = 0; t < 50; t++)    
        for (int i = 0; i < len; i++) {
            int k = i - p[t][i] % len;
            if (k < 0) k += len;
            p[t + 1][i] = p[t][i] + p[t][k];
        }
    ll ans = 0; 
    int t = 50;
    while (b > a && t >= 0) {
        int i = b % len;
        if (b - p[t][i] >= a) {
            ans += ((ll)1 << t);
            b -= p[t][i];
        } else t--;
    }
    cout << ans + go (a, b) << endl;
    return 0;
}