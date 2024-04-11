#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n;

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        vector<int> a(n);
        vector<vector<int>> pos(n+1, vector<int>());
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            pos[a[i]].push_back(i);
        }
            
        set<int> s;
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if (i > 0 && a[i] < a[i-1]) {
                for(int x: s) {
                    for(int j: pos[x]) 
                        a[j] = 0;
                    ++ans;
                }
                s.clear();
            }
            if (a[i] != 0)
                s.insert(a[i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}