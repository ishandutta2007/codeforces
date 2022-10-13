#include <bits/stdc++.h>
using namespace std;

const int SZ = 1000005;

vector<int> primes[SZ];
bool prime[SZ];

int par[SZ];
int sz[SZ];

int find(int x) {
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < SZ; i++) {
        if(prime[i]) {
            primes[i].push_back(i);
            for(int j = 2; j <= (SZ - 1) / i; j++) {
                prime[i * j] = false;
                primes[i * j].push_back(i);
            }
        }
    }
    for(int i = 0; i < SZ; i++)
        par[i] = i, sz[i] = 1;
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < (int) primes[a[i]].size() -  1; j++) {
            merge(primes[a[i]][j], primes[a[i]][j + 1]);
        }
    }
    set<pair<int, int>> sto;
    for(int i = 0; i < n; i++) {
        int look = a[i] + 1;
        int x = find(primes[a[i]][0]);
        for(int j = 0; j < (int) primes[look].size(); j++) {
            int a = find(primes[look][j]);
            sto.insert({x, a});
            sto.insert({a, x});
            for(int k = j + 1; k < (int) primes[look].size(); k++) {
                int b = find(primes[look][k]);
                sto.insert({a, b});
                sto.insert({b, a});
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int s, t; cin >> s >> t;
        --s, --t;
        int x = find(primes[a[s]][0]), y = find(primes[a[t]][0]);
        if(x == y) 
            cout << 0 << "\n";
        else if(sto.count({x, y}))
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}