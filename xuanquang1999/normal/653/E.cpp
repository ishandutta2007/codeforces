#include <bits/stdc++.h>

using namespace std;

struct DSU {
private:
    vector<int> pset;
    int nComp;

public:
    void init(int n) {
        pset.resize(n);
        for(int i = 0; i < n; ++i)
            pset[i] = i;
        nComp = n;
    }

    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }

    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q)
            return false;
        pset[p] = q;
        --nComp;
        return true;
    }

    int getNComp() {
        return nComp;
    }
};

const int MAXN = 300005;

int n, m, k;
vector<int> sep[MAXN];
set<int> segLeft;
DSU s;

void join(int u) {
//    printf("u: %d\n", u);

    for(int i = 1; i < sep[u].size(); ++i) {
        int l = sep[u][i-1]+1, r = sep[u][i]-1;
        if (l > r)
            continue;
        s.unionSet(u, l);

//        printf("%d %d\n", l, r);

        int x;
        while ((x = *segLeft.upper_bound(l)) <= r) {
            s.unionSet(u, x);
            segLeft.erase(x);
        }
    }
}

bool solve() {
    int deg0 = n+2 - sep[0].size();
    if (deg0-1 < k)
        return false;

    for(int u = 0; u <= n; ++u)
        segLeft.insert(u);
    s.init(n);

    for(int u = 1; u < n; ++u)
        join(u);
    if (s.getNComp()-1 > k)
        return false;

    join(0);
    if (s.getNComp() > 1)
        return false;

    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        sep[u].push_back(v);
        sep[v].push_back(u);
    }
    for(int u = 0; u < n; ++u) {
        sep[u].push_back(0);
        sep[u].push_back(n);
        sort(sep[u].begin(), sep[u].end());

//        printf("u: %d\n", u);
//        for(int x: sep[u])
//            printf("%d ", x);
//        puts("");
    }

    puts(solve() ? "possible" : "impossible");

    return 0;
}