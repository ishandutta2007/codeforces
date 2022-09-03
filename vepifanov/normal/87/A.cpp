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
int m, a, b;

int gcd (int a, int b) {
    re a ? gcd (b % a, a) : b;
}


int main() {
    scanf ("%d%d", &a, &b);
    int d = gcd (a, b);
    a /= d;
    b /= d;
    ll A = 0, B = 0;
    if (a < b) { 
        A = (ll)b * a - (ll)a * (a + 1) / 2; 
        B = (ll)a * (a + 1) / 2; 
    } else {
        B = (ll)b * a - (ll)b * (b + 1) / 2;
        A = (ll)b * (b + 1) / 2;
    }
    if (A < B) printf ("Masha\n"); else 
    if (A > B) printf ("Dasha\n"); else printf ("Equal\n");
    return 0;
}