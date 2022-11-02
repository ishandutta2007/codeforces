#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

vector<int> process(vector<int> &v) {
    int k = (int)v.size() + 1;
    vector<int> ret(k), front(k), back(k);
    for (int i = 1; i < k; ++i) {
        front[i] = front[i - 1] + v[i - 1];
    }
    for (int i = 1; i < k; ++i) {
        back[i] = back[i - 1] + v[k - i - 1];
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j <= i; ++j) {
            ret[i] = max(ret[i], front[j] + back[i - j]);
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    vector<int> ans(m + 1);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        vector<int> tmp(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &tmp[j]);
        }
        tmp = process(tmp);
        for (int j = m; j >= 0; --j) {
            for (int k = 1; j - k >= 0 && k < (int)tmp.size(); ++k) {
                ans[j] = max(ans[j], ans[j - k] + tmp[k]);
            }
        }
    }
    printf("%d\n", ans.back());
    return 0;
}