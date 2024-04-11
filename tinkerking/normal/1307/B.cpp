#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N, x;
int a[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&x);
        bool onestep = false;
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            if (a[i] == x) {
                onestep = true;
            }
        }
        sort(a+1,a+N+1);
        int ans = (x + a[N] - 1) / a[N];
        if (!onestep) {
            ans = max(ans, 2);
        }
        printf("%d\n",ans);
    }
}