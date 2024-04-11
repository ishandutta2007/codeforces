#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int loc[100013][1013];
bool on[100013][1013];
int ans[100013];

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int t=1;t<=q;t++) {
        int type;
        scanf("%d",&type);
        for (int i=0;i<n;i++) loc[t][i] = loc[t-1][i];
        ans[t] = ans[t-1];
        if (type==1 || type==2) {
            int a,b;
            scanf("%d%d",&a,&b);
            a-=1; b-=1;
            for (int j=0;j<m;j++) on[t][j] = on[loc[t][a]][j];
            loc[t][a] = t;
            ans[t]-=on[t][b];
            on[t][b] = (type==1);
            ans[t]+=on[t][b];
        } else if (type==3) {
            int a;
            scanf("%d",&a);
            a-=1;
            for (int j=0;j<m;j++) {
                ans[t]-=on[loc[t][a]][j];
                on[t][j] = !on[loc[t][a]][j];
                ans[t]+=on[t][j];
            }
            loc[t][a] = t;
        } else {
            int a;
            scanf("%d",&a);
            for (int i=0;i<n;i++) loc[t][i] = loc[a][i];
            ans[t] = ans[a];
        }
        printf("%d\n",ans[t]);
    }

    return 0;
}