
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll zeros[200500][2], consec_ones[200500];
ll hsh[200500];
ll p[200500], pe[200500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> x;
    y = ((x >> 5) & 1) * 32 + ((x>>4) & 1) * 1 + ((x>>3)&1) * 4 + ((x>>2)&1) * 8 + ((x >> 1) & 1) * 2 + (x & 1) * 16;

    //y = ((x >> 5) & 1) * 32 + ((x>>4) & 1) * 1 + ((x>>3)&1) * 4 + ((x>>2)&1) * 16 + ((x >> 1) & 1) * 2 + (x & 1) * 8;
    //520314
    //502413
    cout << y << "\n";
    return 0;
}