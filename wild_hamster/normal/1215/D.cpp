#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define LOG 18
ll n, x, k, z, m, pos, q;


ll b[100500];
vector<ll> g, f;
vector<ll> a[27][27];
vector<pii> ans;

bool try_min(ll ffr, ll fsum, ll sfr, ll ssum) {
    fsum += 9 * (ffr / 2);
    ssum += 9 * (sfr / 2);
    //cout << fsum << " " << ssum << endl;
    if (fsum < ssum) {
        return true;
    }
    return false;
}

bool try_max(ll ffr, ll fsum, ll sfr, ll ssum) {
    fsum += 9 * ((ffr+1) / 2);
    ssum += 9 * ((sfr+1) / 2);
    //cout << fsum << " " << ssum << endl;
    if (fsum > ssum) {
        return true;
    }
    return false;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    ll fsum = 0, ffr = 0, ssum = 0, sfr = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] == '?') {
            ffr++;
        } else {
            fsum += s[i] - '0';
        }
    }

    for (int i = n/2; i < n; i++) {
        if (s[i] == '?') {
            sfr++;
        } else {
            ssum += s[i] - '0';
        }
    }

    bool hyu = try_min(ffr, fsum, sfr, ssum) || try_min(sfr,ssum,ffr,fsum) ||
            try_max(ffr, fsum, sfr, ssum) || try_max(sfr,ssum,ffr,fsum);
    if (hyu) {
        cout << "Monocarp" << endl;
    } else {
        cout << "Bicarp" << endl;
    }
    return 0;
}