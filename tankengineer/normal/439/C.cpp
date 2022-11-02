#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, p;

vector<int> odd, even;


int main() {
    scanf("%d%d%d", &n, &k, &p);
    p = k - p;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a % 2 == 1) {
            odd.push_back(a);
        } else {
            even.push_back(a);
        }
    }
    if ((int)odd.size() < p || (int)odd.size() % 2 != p % 2) {
        printf("NO\n");
        return 0;
    }
    vector<vector<int> > ans(k);
    for (int i = 0; i < p; ++i) {
        ans[i].push_back(odd[i]);
    }
    int cnt = p;
    for (int i = p; i + 1 < (int)odd.size(); i += 2) {
        if (cnt < k) {
            ans[cnt].push_back(odd[i]);
            ans[cnt].push_back(odd[i + 1]);
            ++cnt;
        } else {
            ans[0].push_back(odd[i]);
            ans[0].push_back(odd[i + 1]);
        }
    }
    for (int i = 0; i < (int)even.size(); ++i) {
        if (cnt < k) {
            ans[cnt++].push_back(even[i]);
        } else {
            ans[0].push_back(even[i]);
        }
    }
    if (cnt < k) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < (int)ans.size(); ++i) {
            printf("%d", (int)ans[i].size());
            for (int j = 0; j < (int)ans[i].size(); ++j) {
                printf(" %d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}