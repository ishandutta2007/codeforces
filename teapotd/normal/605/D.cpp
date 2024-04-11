#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int INF = 1e9+100;

struct SegTree {
    struct Elem {
        int y, ind;

        bool operator<(const Elem& r) const {
            return mp(y, ind) < mp(r.y, r.ind);
        }
    };

    vector<set<Elem>> V;
    int len;

    SegTree(int wid) {
        for (len = 1; len <= wid; len *= 2);
        V.resize(len*2);
    }

    void insert(int x, int y, int ind) {
        Elem e{y, ind};
        x += len;
        while (x > 0) {
            V[x].insert(e);
            x /= 2;
        }
    }

    void erase(int x, int y, int ind) {
        Elem e{y, ind};
        x += len;
        while (x > 0) {
            V[x].erase(e);
            x /= 2;
        }
    }

    void collect(Vi& out, int vBegin, int vEnd, int limY, int i, int begin, int end) {
        if (vEnd <= begin || vBegin >= end) return;

        if (vBegin <= begin && vEnd >= end) {
            each(e, V[i]) {
                if (e.y >= limY) return;
                out.pb(e.ind);
            }
            return;
        }

        int mid = (begin+end) / 2;
        collect(out, vBegin, vEnd, limY, i*2, begin, mid);
        collect(out, vBegin, vEnd, limY, i*2+1, mid, end);
    }

    void collect(Vi& out, int vBegin, int vEnd, int limY) {
        collect(out, vBegin, vEnd, limY, 1, 0, len);
    }
};

struct Card {
    Pii from, to;
    int prev{-1}, dist{INF};
};

int compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    int last = -1, ind = -1;
    each(e, vec) {
        if (*e != last) {
            last = *e;
            ind++;
            if (ind == 0 && last > 0) ind++;
        }
        *e = ind;
    }
    return ind+1;
}

void run() {
    int n; cin >> n;
    vector<Card> cards(n);
    vector<int*> xCoords;

    each(e, cards) {
        cin >> e.from.x >> e.from.y;
        cin >> e.to.x >> e.to.y;
        xCoords.pb(&e.from.x);
        xCoords.pb(&e.to.x);
    }

    int dimX = compressVec(xCoords);
    SegTree tree(dimX);

    rep(i, 0, n) {
        auto& e = cards[i];
        tree.insert(e.from.x, e.from.y, i);
    }

    Vi nxt;
    queue<int> que;
    que.push(-1);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        int x = 0, y = 0, d = 0;
        if (v != -1) {
            x = cards[v].to.x;
            y = cards[v].to.y;
            d = cards[v].dist;

            if (v == n-1) {
                cout << d << '\n';

                nxt.clear();
                while (v != -1) {
                    nxt.pb(v);
                    v = cards[v].prev;
                }

                reverse(all(nxt));
                each(i, nxt) cout << i+1 << ' ';
                cout << '\n';
                return;
            }
        }

        nxt.clear();
        tree.collect(nxt, 0, x+1, y+1);

        each(ind, nxt) {
            auto& e = cards[ind];
            assert(e.dist == INF);
            e.prev = v;
            e.dist = d+1;
            tree.erase(e.from.x, e.from.y, ind);
            que.push(ind);
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    run();
    return 0;
}