#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, p[N], l[N], r[N];

struct Query{
    int reach, cost, id;

    Query(int reach, int cost, int id) : reach(reach), cost(cost), id(id) {}
};

bool operator < (const Query &a, const Query &b) {
    return a.reach < b.reach || a.reach == b.reach && a.id < b.id;
}

struct SetQ {
    int delta;
    
    set<Query> tr;

    SetQ() {
        delta = 0;
        tr.clear();
    }

    int size() {
        return tr.size();
    }

    Query begin() {
        Query q = *tr.begin();
        q.cost += delta; 
        return q;
    }

    void erase(Query q) {
        q.cost -= delta;
        tr.erase(q);
    }
    
    void insert(Query q) {
        q.cost -= delta;
        tr.insert(q);
    }

    void add(int d) {
        delta += d;
    }
};

void merge(SetQ &ch, SetQ &fa) {
    if (ch.size() > fa.size()) {
        fa.tr.swap(ch.tr);
        swap(fa.delta, ch.delta);
    }
    while (ch.size()) {
        Query q = ch.begin();
        fa.insert(q);
        ch.erase(q);
    }
}

#define next NEXT

int next[N], ans[N];

const int INF = 2000000005;

SetQ que[N];

int main() {
    scanf("%d", &n);
    p[n] = INF, l[n] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", p + i, l + i);
        r[i] = p[i] + l[i];
    }
    vector<int> s;
    for (int i = n - 1; i >= 0; --i) {
        while (s.size() && r[s.back()] <= r[i]) {
            s.pop_back();
        }
        if (s.size() == 0) {
            next[i] = n;
        } else {
            next[i] = s.back();
        }
        s.push_back(i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        que[x].insert(Query(p[y], 0, i));
    }
    for (int i = 0; i < n; ++i) {
        while (que[i].size()) {
            Query q = que[i].begin();
            if (q.reach <= p[next[i]]) {
                ans[q.id] = q.cost + max(0, q.reach - r[i]);
                que[i].erase(q);
            } else {
                break;
            }
        }
        que[i].add(max(0, p[next[i]] - r[i]));
        merge(que[i], que[next[i]]);
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}