#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int ind[200010], b[200010], a[200010];
int fuck[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) ind[i] = 0;
        vector<int>cnm;
        for (int i = 1; i <= n; i++) {
            scanf("%d",&b[i]);
            ind[b[i]]++;
            fuck[i] = 0;
            a[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) {
                int last = -1;
                for (int j = i; !fuck[j]; j = b[j]) {
                    fuck[j] = i;
                    cnm.push_back(j);
                    //printf("cnm %d\n",j);
                }
            }
        }
        if (cnm.size() > 0) {
            for (int i = 0; i < cnm.size() - 1; i++) {
                a[cnm[i]] = cnm[i + 1];
                //printf("%d-->%d\n",cnm[i],cnm[i+1]);
            }
            a[cnm[cnm.size() - 1]] = cnm[0];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) a[i] = b[i];
            ans += (a[i] == b[i]);
        }
        printf("%d\n",ans);
        for (int i = 1; i <= n; i++) {
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
}