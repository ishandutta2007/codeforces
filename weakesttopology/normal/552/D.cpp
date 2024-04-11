#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
#define mp make_pair

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main()
{ _
    int n; cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    map<pair<int, ii>, int> W;

    for (int i = 0; i < n; ++i)
    {
        map<ii, set<int>> H;
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
                continue;
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];

            if (dx == 0)
                dy = 1;
            else if (dy == 0)
                dx = 1;
            else
            {
                if (dy < 0)
                {
                    dx *= -1;
                    dy *= -1;
                }
                int d = __gcd(dx, dy);
                dx /= d;
                dy /= d;
            }

            H[mp(dx, dy)].insert(j);
        }
        for (auto [k, v] : H)
        {
            v.insert(i);
            int m = *v.begin();
            W[mp(m, k)] = v.size();
        }
    }

    ll N = n;
    ll total = N * (N - 1) * (N - 2) / 6;
    for (auto [k, v] : W)
        total -= v * (v - 1) * (v - 2) / 6;

    cout << total << endl;

    exit(0);
}