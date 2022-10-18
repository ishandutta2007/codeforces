#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define maxN 100005

int n, a[maxN], asum;
vector <int> ans;

int main() {
    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    fdto(b, 31, 0) {
        ans.clear();
        fto(i, 0, n-1)
            if ((a[i] >> b) & 1 == 1) ans.pb(a[i]);
        if (ans.size() == 0) continue;

//        printf("%d\n", ans.size());
//        for(int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
//        printf("\n");

        asum = ans[0];
        for(int i = 1; i < ans.size(); ++i) asum&=ans[i];

        int x = round(pow(2, b));
        if (asum % x == 0) {
            printf("%d\n", ans.size());
            for(int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
//            printf("ans\n");
            return 0;
        }
    }

//    printf("-1\n");
    printf("%d\n", n);
    fto(i, 0, n-1) printf("%d ", a[i]);
    return 0;
}