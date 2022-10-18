#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, p[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) 
            scanf("%d", &p[i]);

        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            int k;
            while ((k = v.size()) >= 2 && 1LL * (v[k-2] - v[k-1]) * (v[k-1] - p[i]) > 0)
                v.pop_back();
            v.push_back(p[i]);            
        }

        printf("%d\n", v.size());
        for(int x: v)
            printf("%d ", x);
        puts("");
    }

    return 0;
}