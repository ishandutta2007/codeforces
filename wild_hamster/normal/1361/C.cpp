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
#include <unordered_map>

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
ll b[1200500], a[1200500], d[1205000], deleted[1200500];
vector<pii> g[1205000];
map<pii, vector<ll> > zalupas;
ll deg[1205000];
ll fuck(ll x, ll y) {
    return x * n + y;
}

int main() {
    ll nn;
    int tmp;
    scanf("%d", &tmp);
    nn = tmp;
    ll hyu = -1;
    ll bad = 0;
    for (int i = 0; i < nn; i++) {
        a[i] = 2 * i + 1;
        b[i] = 2 * i + 2;
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        a[i] = tmp1;
        b[i] = tmp2;
        if (hyu == -1) {
            hyu = a[i];
        }
        if (hyu != a[i] || hyu != b[i]) {
            bad = 1;
        }
    }
    if (nn == 1) {
        for (int i = 20; i >= 0; i--) {
            if (((a[0] ^ b[0]) % (1<<i)) == 0) {
                cout << i << "\n";
                cout << 1 << " " << 2 << "\n";
                return 0;
            }
        }
    }

    for (int p = 20; p >= 0; p--) {
        n = (1<<p);
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 0; i <= n; i++) {
            deg[i] = 0;
        }
        zalupas.clear();
        for (int i = 0; i < nn; i++) {
            deleted[i] = 0;
        }
        for (int i = 0; i < nn; i++) {
            g[b[i] % n].push_back(mp(a[i] % n, i));
            g[a[i] % n].push_back(mp(b[i] % n, i));
            deg[b[i]%n]++;
            deg[a[i]%n]++;
        }

        int first = 0;
        while (!deg[first]) ++first;

        int v1 = -1, v2 = -1;
        bool bad = false;
        for (int i = 0; i < n; ++i)
            if (deg[i] & 1)
                if (v1 == -1)
                    v1 = i;
                else if (v2 == -1)
                    v2 = i;
                else
                    bad = true;

        if (v1 != -1) {
            continue;
        }

        stack<int> st;
        st.push(first);
        vector<int> res;
        while (!st.empty()) {
            int v = st.top();
            int i = n;
            while (!g[v].empty() && deleted[g[v].back().Y]) {
                g[v].pop_back();
            }
            if (!g[v].empty()) {
                deleted[g[v].back().Y] = 1;
                i = g[v].back().X;
                g[v].pop_back();
            }
            if (i == n) {
                res.push_back(v);
                st.pop();
            } else {
                st.push(i);
            }
        }
        ll hyu = 0;
        for (int i = 0; i < n; i++) {
            if (!g[i].empty()) {
                hyu = 1;
            }
        }
        if (hyu) {
            continue;
        }

        cout << p << "\n";
        for (int i = 0; i < nn; i++) {
            ll x = a[i] % n;
            ll y = b[i] % n;
            ll id = i;
            if (x > y) {
                swap(x, y);
                id += nn;
            }
            zalupas[mp(x,y)].push_back(id);
        }
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            ll x = res[i];
            ll y = res[i+1];
            ll zh = 0;
            if (x > y) {
                swap(x, y);
                zh += nn;
            }
            int id = zalupas[mp(x,y)].back();
            zalupas[mp(x,y)].pop_back();
            id = (id + zh ) % (2 * nn);
            if (id < nn) {
                printf("%d %d ", 2 * id + 1, 2 * id + 2);
            } else {
                id -= nn;

                printf("%d %d ", 2 * id + 2, 2 * id + 1);
            }
        }
        break;
    }
    return 0;
}