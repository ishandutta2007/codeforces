#include <bits/stdc++.h>

using namespace std;

const long long oo = 1000000000000000007LL;

class ExtendedMultiset {
private:
    map<int, long long> lo, hi;
    int delta;
    long long cntLo, cntHi;
    long long sumLo, sumHi;

public:
    ExtendedMultiset() {
        delta = 0;
        cntLo = cntHi = 0;
        sumLo = sumHi = 0;
    }

    void updateAll(int val) {
        int newDelta = delta - val;
        vector<pair<int, long long>> listLo, listHi;

        while (!lo.empty() && lo.rbegin()->first >= newDelta) {
            pair<int, long long> p = *lo.rbegin();
            cntLo -= p.second;
            sumLo -= (delta - p.first) * p.second;
            lo.erase(p.first);
            listHi.push_back(p);
        }

        while (!hi.empty() && hi.begin()->first < newDelta) {
            pair<int, long long> p = *hi.begin();
            cntHi -= p.second;
            sumHi -= (p.first - delta) * p.second;
            hi.erase(p.first);
            listLo.push_back(p);
        }

        sumLo -= cntLo * val;
        sumHi += cntHi * val;

        for(auto p: listLo) {
            cntLo += p.second;
            sumLo += (newDelta - p.first) * p.second;
            lo.insert(p);
        }

        for(auto p: listHi) {
            cntHi += p.second;
            sumHi += (p.first - newDelta) * p.second;
            hi.insert(p);
        }

        delta = newDelta;
    }

    void update(int key, int val) {
        if (key < delta) {
            lo[key] += val;
            cntLo += val;
            sumLo += 1LL * (delta - key) * val;
        } else {
            hi[key] += val;
            cntHi += val;
            sumHi += 1LL * (key - delta) * val;
        }
    }

    long long getSum() {
        return sumLo + sumHi;
    }
};

struct Point {
    int x, id, type;

    bool inline operator < (const Point &rhs) const {
        return x < rhs.x;
    }
};

int m, n;
vector<Point> p;

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        p.push_back({x, i, 1});
    }
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        p.push_back({x, i, -1});
    }

    sort(p.begin(), p.end());
    p.push_back(p[0]);
    p[2*n].x += m;

    ExtendedMultiset s;

    int curPref = 0;
    for(int i = 0; i < 2*n; ++i) {
        curPref += p[i].type;
        s.update(curPref, p[i+1].x - p[i].x);
    }

    int bestInd = -1;
    long long minCost = oo;
    for(int i = 0; i < 2*n; ++i) {
        long long cost = s.getSum();
        if (cost < minCost) {
            minCost = cost;
            bestInd = i;
        }
        s.updateAll(-p[i].type);
    }

    vector<int> idA, idB;
    for(int i = 0; i < 2*n; ++i) {
        int j = (i + bestInd) % (2*n);
        if (p[j].type == 1)
            idA.push_back(p[j].id);
        else
            idB.push_back(p[j].id);
    }

    vector<int> ans(n, -1);
    for(int i = 0; i < n; ++i)
        ans[idA[i]] = idB[i];

    printf("%lld\n", minCost);
    for(int i = 0; i < n; ++i)
        printf("%d ", ans[i] + 1);

    return 0;
}