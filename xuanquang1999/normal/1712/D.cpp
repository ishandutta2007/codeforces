#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, k, a[MAXN], cntL[MAXN], cntR[MAXN];

bool check(int x) {
    cntL[0] = 0;
    for(int i = 1; i <= n; ++i) 
        cntL[i] = cntL[i-1] + (a[i] < (x+1)/2);
    cntR[n+1] = 0;
    for(int i = n; i >= 1; --i)
        cntR[i] = cntR[i+1] + (a[i] < (x+1)/2);

    for(int i = 1; i < n; ++i) {
        int cnt = cntL[i-1] + cntR[i+2] + (a[i] < x) + (a[i+1] < x);
        if (cnt <= k) return true;
    }
    return false;
}

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        
        int l = 1, r = 1e9, res = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(mid)) {
                res = mid;
                l = mid+1;
            } else 
                r = mid-1;
        }

        printf("%d\n", res);
    }

    return 0;
}