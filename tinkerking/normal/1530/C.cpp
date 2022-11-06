#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, k;
        scanf("%d",&n);
        vector<int>a(n);
        vector<int>b(n);
        auto calc = [](vector<int> val) {
            sort(val.begin(), val.end());
            reverse(val.begin(), val.end());
            int k = val.size();
            k = k - k / 4;
            int ret = 0;
            for (int i = 0; i < k; i++) ret += val[i];
            //for (auto &t : val) printf("%d ",t);
            //printf("%d\n",ret);
            return ret;
        };
        for (int i = 0; i < n; i++) {
            scanf("%d",&b[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int va = calc(a);
        int vb = calc(b);
        if (vb >= va) {
            puts("0");
            continue;
        }
        int L = 0, R = 4 * n;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            vector<int> tmp = b;
            vector<int> tmpa = a;
            for (int i = 0; i < mid; i++) {
                tmp.push_back(100);
                tmpa.push_back(0);
            }
            if (calc(tmp) >= calc(tmpa)) R = mid;
            else L = mid;
        }
        printf("%d\n",R);
    }
}