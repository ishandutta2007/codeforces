#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool v[maxn];
vector<int> pr;
int mindiv[maxn], ind[maxn];
unordered_set<int> st[10000];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), ind[i] = pr.size(), mindiv[i] = i;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            mindiv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

int check(int now) {
    int t = now;
    while (now > 1) {
        if (st[ind[mindiv[now]]].size()) return *st[ind[mindiv[now]]].begin();
        now /= mindiv[now];
    }
    return -1;
}

void ins(int now) {
    int t = now;
    while (now > 1) {
        int d = mindiv[now];
        st[ind[d]].insert(t);
        while (now % d == 0) now /= d;
    }
}

void del(int now) {
    int t = now;
    while (now > 1) {
        int d = mindiv[now];
        st[ind[d]].erase(t);
        while (now % d == 0) now /= d;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve(); memset(v, false, sizeof(v));
    int n, m; cin >> n >> m; while (m--) {
        char c; int k; cin >> c >> k;
        if (c == '+') {
            if (v[k]) { cout << "Already on" << endl; continue; }
            int f = check(k);
            if (f == -1) cout << "Success" << endl, v[k] = true, ins(k);
            else cout << "Conflict with " << f << endl;
        } else {
            if (!v[k]) cout << "Already off" << endl;
            else cout << "Success" << endl;
            del(k);
            v[k] = false;
        }
    }
    return 0;
}