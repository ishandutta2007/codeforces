#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n;
int a[MAXN];
vector<int> f[10];

void solve(int casi){
    scanf("%d", &n);
    for (int j = 0; j <= 3; j++) f[j].clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[a[i]].push_back(i);
    }
    if (f[0].size() == n) {
        puts("0"); return;
    }
    if (f[1].size() == 0) {
        puts("-1"); return;
    }
    int lst = f[1].back();
    if (!f[3].empty() && f[3].back() > lst) {
        puts("-1"); return;
    }
    if (!f[2].empty() && f[2].back() > lst) {
        puts("-1"); return;
    }
    vector<PII> ans;
    int p = -1, q = -1, flag = 1;
    if (f[3].empty()) {
        if (f[2].empty()) {
            while (!f[1].empty()) {
                ans.emplace_back(f[1].back(), -1);
                f[1].pop_back();
            }
        }
        else {
            while (!f[1].empty()) {
                if (f[2].empty()) {
                    ans.emplace_back(f[1].back(), -1);
                }
                else {
                    if (f[2].back() < f[1].back()) {
                        ans.emplace_back(f[1].back(), f[2].back());
                        f[2].pop_back();
                    }
                    else {
                        flag = 0;
                    }
                }
                f[1].pop_back();
            }
        }
    }
    else {
        if (f[2].empty()) {
            p = f[1].back();
            f[1].pop_back();
            while (!f[1].empty()) {
                ans.emplace_back(f[1].back(), -1);
                f[1].pop_back();
            }
        }
        else {
            if (f[2].back() > f[3].back()) {
                p = f[1].back();
                q = f[2].back();
                f[1].pop_back();
                f[2].pop_back();
            }
            else {
                p = f[1].back();
                f[1].pop_back();
            }
            while (!f[1].empty()) {
                if (f[2].empty()) {
                    ans.emplace_back(f[1].back(), -1);
                }
                else {
                    if (f[2].back() < f[1].back()) {
                        ans.emplace_back(f[1].back(), f[2].back());
                        f[2].pop_back();
                    }
                    else {
                        flag = 0;
                    }
                }
                f[1].pop_back();
            }
        }
    }
    if (!f[2].empty() || !flag) {
        puts("-1"); return ;
    }
    int cnt = 1;
    vector<PII> ret;
    if (!f[3].empty()) {
        ret.emplace_back(1, f[3][0]);
        for (int i = 1; i < f[3].size(); i++) {
            ret.emplace_back(cnt, f[3][i]);
            cnt++;
            ret.emplace_back(cnt, f[3][i]);
        }
        if (q != -1) {
            ret.emplace_back(cnt, q);
            cnt++;
            ret.emplace_back(cnt, q);
            ret.emplace_back(cnt, p);
            cnt++;
        }
        else {
            ret.emplace_back(cnt, p);
            cnt++;
            ret.emplace_back(cnt, p);
            cnt++;
        }
    }
    for (auto &x : ans) {
        if (x.second == -1) {
            ret.emplace_back(cnt, x.first);
            cnt++;
        }
        else {
            ret.emplace_back(cnt, x.second);
            ret.emplace_back(cnt, x.first);
            cnt++;
        }
    }
    printf("%d\n", (int)(ret.size()));
    for (auto &x : ret) {
        printf("%d %d\n", x.first, x.second);
    }
}

int main(){
    int T = 1;
    // scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}