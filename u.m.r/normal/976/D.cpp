#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int sz, n;

vector<PII> ans;

void gao(const vector<int> &a) {
    if (a.size() == 0) {
        sz = 1;
        return ;
    }
    if (a.size() == 1) {
        int p = a[0];
        sz = p + 1;
        for (int i = 1; i <= p; i++) {
            for (int j = i + 1; j <= sz; j++) {
                ans.emplace_back(i, j);
            }
        }
        return ;
    }
    vector<int> b;
    int m = a.size();
    for (int i = 1; i + 1 < m; i++) {
        b.push_back(a[i] - a[0]);
    }
    int p = a[0];
    int q = a[m - 1] - a[m - 2];
    gao(b);
    sz += q;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= sz + i - 1; j++) {
            ans.emplace_back(sz + i, j);
        }
    }
    sz += p;
}

void solve(int casi){
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    gao(a);
    printf("%d\n", (int)(ans.size()));
    for (auto &x : ans) {
        printf("%d %d\n", x.first, x.second);
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}