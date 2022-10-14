#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  q, ans, w[100500], d[100500], p[100500], a[200500];
pii b[200500];
map<ll, ll> f;
string bullshit = "fsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvkdfjgkdsfjgkdjsfkgjdskfgjkdfjgkdsfjgkdsfjgksdjfgkuwretouweortudsfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvkdfjgkdsfjgkdjsfkgjdskfgjkdfjgkdsfjgkdsfjgksdjfgkuwretouweortudsfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvfsdlgjkhfdskjghdsjkfghsdjkfghkdfjhgjkdsfhgkjdsvnskdcwxfxowqiedhweutriwuegmseivbyurtboisdmvnciudviudfbvkdfjgkdsfjgkdjsfkgjdskfgjkdfjgkdsfjgkdsfjgksdjfgkuwretouweortudsdsmfgjhdsfjghjsdf";
ll get_seed() {
    ll x = 0;
    for (int i = 0; i < bullshit.size(); i++) {
        x = (x * 31 + bullshit[i])%MOD;
    }
}

bool is_pal(string s) {
    int n = s.size();
    for (int i = 0; i < n/ 2; i++)
        if (s[i] != s[n-i-1])
            return false;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(get_seed());
    string s;
    cin >> s;
    n = s.size();
    bool imp = true;
    set<char> f;
    for (int i = 0; i < n / 2; i++) {
        f.insert(s[i]);
        f.insert(s[n-i-1]);
    }
    if (f.size() <= 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i < n-1; i++) {
        string t;
        for (int j = i; j < n; j++)
            t.push_back(s[j]);
        for (int j = 0; j < i; j++)
            t.push_back(s[j]);
        if (is_pal(t) && t != s) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}