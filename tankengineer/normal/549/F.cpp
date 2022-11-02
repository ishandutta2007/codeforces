#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300005;
int n, k;

int a[N];

long long sum[N];

bool vis[N];

map<int, int> tr[N];

int fa[N], size[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[find(u)] = fa[find(v)];
    size[v] += size[u];
}

long long merge(int i, int j, int t, int l) {
    long long ret = 0;
    l = l - size[i] + 1;
    int tt = sum[l] % k, x = (tt + t) % k;
    if (tr[j].count(x)) {
        ret += tr[j][x];
    }
    if (tr[i].size() < tr[j].size()) {
        merge(i, j);
        for (map<int, int>::iterator it = tr[i].begin(); it != tr[i].end(); ++it) {
            int d = it->first, cnt = it->second,
                x = (d + t) % k;
            if (tr[j].count(x)) {
                ret += (long long)cnt * tr[j][x];
            }
        }
        for (map<int, int>::iterator it = tr[i].begin(); it != tr[i].end(); ++it) {
            int d = it->first, cnt = it->second;
            tr[j][d] += cnt;
        }
    } else {
        merge(j, i);
        for (map<int, int>::iterator it = tr[j].begin(); it != tr[j].end(); ++it) {
            int d = it->first, cnt = it->second,
                x = (d - t + k) % k;
            if (tr[i].count(x)) {
                ret += (long long)cnt * tr[i][x];
            }
        }
        for (map<int, int>::iterator it = tr[j].begin(); it != tr[j].end(); ++it) {
            int d = it->first, cnt = it->second;
            tr[i][d] += cnt;
        }
    }
    return ret;
}

void getInt(int &a) {
    a = 0;
    char ch;
    while (!isdigit(ch = getchar())) {
        continue;
    }
    a = ch - '0';
    while (isdigit(ch = getchar())) {
        a = a * 10 + (ch - '0');
    }
}

int main() {
    long long ans = 0;
    getInt(n);
    getInt(k);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        getInt(a[i]);
        sum[i + 1] = sum[i] + a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int pos = v[i].second;
        fa[pos] = pos;
        size[pos] = 1;
        vis[pos] = true;
        int t = sum[pos + 1] % k, tt = a[pos] % k;
        tr[pos][t]++;
        if (pos > 0 && vis[pos - 1]) {
            --ans;
            ans += merge(find(pos - 1), find(pos), tt, pos - 1);
        }
        if (pos < n - 1 && vis[pos + 1]) {
            if (tr[find(pos + 1)].count((t + tt) % k)) {
                ans -= tr[find(pos + 1)][(t + tt) % k];
            }
            ans += merge(find(pos), find(pos + 1), tt, pos);
        }
    }
    cout << ans << endl;
    return 0;
}