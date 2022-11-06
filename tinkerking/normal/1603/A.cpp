#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        int done = 0;
        while(n) {
            int idx = -1; 
            for (int i = n; i >= 1; i--) {
                if (a[i] % (i + 1) != 0) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) break;
            for (int i = idx; i <= n - 1; i++) {
                a[i] = a[i + 1];
            }
            n--;
        }
        puts(n == 0 ? "YES" : "NO");
    }
}