#include <bits/stdc++.h>
using namespace std;

vector<int> dl, dr;
int cnt[10];

bool check(int p, int lp, int rp) {
    if (p < 0) return true;
    if (lp == 1 && rp == 0) {
        for (int i = dl[p] + 1; i < 10; ++i) if (cnt[i]) return true;
        if (cnt[dl[p]] == 0) return false;
        --cnt[dl[p]];
        bool ret = check(p - 1, 1, 0);
        ++cnt[dl[p]];
        return ret;
    }
    if (lp == 0 && rp == 1) {
        for (int i = 0; i < dr[p]; ++i) if (cnt[i]) return true;
        if (cnt[dr[p]] == 0) return false;
        --cnt[dr[p]];
        bool ret = check(p - 1, 0, 1);
        ++cnt[dr[p]];
        return ret;
    }
    if (dl[p] == dr[p]) {
        if (cnt[dl[p]] == 0) return false;
        --cnt[dl[p]];
        bool ret = check(p - 1, lp, rp);
        ++cnt[dl[p]];
        return ret;
    }
    if (dl[p] < dr[p]) {
        for (int i = dl[p] + 1; i < dr[p]; ++i) if (cnt[i]) return true;
        bool ret = false;
        if (cnt[dl[p]]) {
            --cnt[dl[p]];
            ret |= check(p - 1, 1, 0);
            ++cnt[dl[p]];
        } 
        if (cnt[dr[p]]) {
            --cnt[dr[p]];
            ret |= check(p - 1, 0, 1);
            ++cnt[dr[p]];
        }
        return ret;
    }
    return false;
}

long long dfs(int x, int k) {
    if (k == 0) if (check(dl.size() - 1, 1, 1)) return 1;
    long long ret = 0;
    if (x + 1 < 10) ret += dfs(x + 1, k);
    ++cnt[x];
    if (k) ret += dfs(x, k - 1);
    --cnt[x];
    return ret;
}

int main() {
    long long l, r; scanf("%lld %lld", &l, &r);
    while (r) dr.push_back(r % 10), r /= 10;    
    while (l) dl.push_back(l % 10), l /= 10;    
    while (dl.size() < dr.size()) dl.push_back(0);
    long long ans = dfs(0, dr.size());
    printf("%lld\n", ans);
    return 0;
}