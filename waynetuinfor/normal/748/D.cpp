#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
map<string, int> mid;
string to[maxn];
vector<int> c[maxn];
bool v[maxn], pal[maxn];
long long va[maxn], vb[maxn];

int get(const string &s) {
    if (mid.find(s) == mid.end()) {
        mid[s] = mid.size();
        to[mid[s]] = s;
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) pal[mid[s]] = true;
    }
    return mid[s];
}

int find(int idx) {
    string s = to[idx]; reverse(s.begin(), s.end());
    if (mid.find(s) == mid.end()) return -1;
    return mid[s];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k, n; cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        string s; int v; cin >> s >> v;
        int sid = get(s);
        c[sid].push_back(v);
    }
    for (int i = 1; i <= mid.size(); ++i) {
        sort(c[i].begin(), c[i].end());
        reverse(c[i].begin(), c[i].end());
    }
    long long ans = 0;
    for (int i = 1; i <= mid.size(); ++i) if (!v[i] && !pal[i]) {
        int mat = find(i);
        if (mat == -1) continue;
        v[mat] = true;
        for (size_t p = 0; p < min(c[i].size(), c[mat].size()); ++p) {
            if (c[i][p] + c[mat][p] >= 0) ans += c[i][p] + c[mat][p];
            else break;
        }
    }
    long long sum = 0;
    for (int i = 1; i <= mid.size(); ++i) if (pal[i]) {
        for (size_t p = 0; p < c[i].size(); p += 2) {
            if (p + 1 >= c[i].size()) break;
            if (c[i][p] + c[i][p + 1] >= 0) va[i] += c[i][p] + c[i][p + 1];
            else break;
        }        
        vb[i] = c[i][0];
        for (size_t p = 1; p < c[i].size(); p += 2) {
            if (p + 1 >= c[i].size()) break;
            if (c[i][p] + c[i][p + 1] >= 0) vb[i] += c[i][p] + c[i][p + 1];
        }
        sum += va[i];
    }
    long long pv = sum;
    for (int i = 1; i <= mid.size(); ++i) if (pal[i]) {
        pv = max(pv, sum - va[i] + vb[i]);
    }
    ans += pv;
    cout << ans << endl;
    return 0;
}