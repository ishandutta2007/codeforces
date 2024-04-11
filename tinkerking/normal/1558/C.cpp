#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[20111];
vector<int> ans;

void flip(int p) {
    reverse(a + 1, a + p + 1);
    ans.push_back(p);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        bool OK = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
            if (a[i] % 2 != i % 2) {
                OK = false;
            }
        }
        if (!OK) {
            puts("-1");
            continue;
        }
        ans.clear();
        for (int m = n; m >= 3; m -= 2) {
            int p1 = -1, p2 = -1;
            for (int i = 1; i <= m; i++) {
                if (a[i] == m) p1 = i;
            }
            flip(p1);
            // m ... m - 1
            for (int i = 1; i <= m; i++) {
                if (a[i] == m - 1) p2 = i; 
            }
            flip(p2 - 1);
            // ...  m m - 1 x
            flip(p2 + 1);
            // x m - 1 m
            flip(3);
            flip(m);
        }
        for (int i = 1; i <= n; i++) {
            assert(a[i] == i);
        }
        printf("%d\n",ans.size());
        for (auto &t : ans) printf("%d ",t);
        puts("");
    }
}