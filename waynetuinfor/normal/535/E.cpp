#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const double eps = 1e-9;
int s[maxn], r[maxn];
double a[maxn], b[maxn];
int st[maxn];
vector<int> equiv[maxn];
map<pair<int, int>, int> rep;
bool f[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &s[i], &r[i]);
    vector<int> o;
    for (int i = 0; i < n; ++i) {
        if (rep.find(make_pair(s[i], r[i])) != rep.end()) equiv[rep[make_pair(s[i], r[i])]].push_back(i);
        else o.push_back(i), rep[make_pair(s[i], r[i])] = i;
    }
    for (int i : o) a[i] = 1.0 * (r[i] - s[i]) / s[i] / r[i], b[i] = 1.0 / r[i];
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return tie(a[i], b[i]) > tie(a[j], b[j]); });
    int p = 0;
    for (int i = 0; i < o.size(); ++i) {
        int z = o[i];
        while (p >= 2) {
            int x = st[p - 1], y = st[p - 2]; 
            if ((b[y] - b[z]) * 1ll * (a[x] - a[y]) < (b[y] - b[x]) * 1ll * (a[z] - a[y])) --p;
            else break;
        }
        st[p++] = z;
    }
    vector<int> ans;
    int z = 0;
    for (int i = 0; i < p - 1; ++i) {
        int l = st[i], r = st[i + 1];
        double x = 1.0 * (b[l] - b[r]) / (a[r] - a[l]);
        if (x < 0.0 || fabs(x) < eps) f[l] = true; 
    }
    for (int i = p - 1; i > 0; --i) {
        int l = st[i - 1], r = st[i];
        double x = 1.0 * (b[l] - b[r]) / (a[r] - a[l]);
        if (x > 1.0 || fabs(x - 1) < eps) f[r] = true; 
    }
    for (int i = 0; i < p; ++i) if (!f[st[i]]) {
        ans.push_back(st[i]);
        for (int j = 0; j < equiv[st[i]].size(); ++j) ans.push_back(equiv[st[i]][j]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i] + 1); puts("");
    return 0;
}