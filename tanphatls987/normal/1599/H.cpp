#include <bits/stdc++.h>

using namespace std;



typedef long long ll;
typedef pair<ll, ll> ii;

#define X first
#define Y second

const ll INF = 1e9;
const double EPS = 1e-8;

template <class T>
bool minimize(T &x, T y) {
    if (y < x) x = y;
    else return 0;
    return 1;
}

const int N = 1e6 + 10;


long long ask(ll x, ll y) {
    cout << "? " << x << " " << y << endl;
    ll ans; cin >> ans;
    return ans;
}
int main() {
    ll v00 = ask(1, 1), v01 = ask(1, INF);
    ll low0 = INF - v01, high0 = 1 + v00;

    ll c0 = (low0 + high0) / 2;
    ll dx0 = ask(1, c0), dy0 = v00 - dx0;


    ll v11 = ask(INF, INF);
    ll dx1 = ask(INF, c0), dy1 = v11 - dx1;

    cout << "! " << dx0 + 1 << " " << dy0 + 1 << " " << INF - dx1 << " " << INF - dy1 << endl;
}