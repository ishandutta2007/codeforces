#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int a[2];
        set<int> ans;
        scanf("%d%d",&a[0],&a[1]);
        int m = a[0] + a[1];
        int serve[2];
        for (int p = 0; p <= 1; p++) {
            serve[0] = serve[1] = m / 2;
            serve[p] += m % 2;
            for (int get_alice = 0; get_alice <= serve[0]; get_alice++) {
                int get_bob;
                int lose_alice;
                int lose_bob;
                lose_alice = serve[0] - get_alice;
                lose_bob = a[0] - get_alice;
                get_bob = serve[1] - lose_bob;
                if (lose_alice < 0 || lose_bob < 0 || get_bob < 0) continue;
                ans.insert(lose_alice + lose_bob);
            }
        }
        printf("%d\n",ans.size());
        for (auto &t : ans) {
            printf("%d ",t);
        }
        puts("");
    }
}