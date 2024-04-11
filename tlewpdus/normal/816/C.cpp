#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
int ma[110][110];
int ans[1000100];
bool row[1000100];

int main() {
    int i, j, p = 0;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) scanf("%d",&ma[i][j]);
    }
    for (i=1;i<n;i++) {
        int tval = ma[i][0]-ma[0][0];
        for (j=0;j<m;j++) if (ma[i][j]-ma[0][j]!=tval) {
            printf("-1\n");
            return 0;
        }
    }
    int mini = 987654321, t = 0;
    for (i=0;i<n;i++) {
        if (mini>ma[i][0]) {
            mini = ma[i][0];
            t = i;
        }
    }
    for (i=0;i<n;i++) {
        int tval = ma[i][0]-ma[t][0];
        for (j=0;j<tval;j++) {
            row[p] = true;
            ans[p++] = i+1;
        }
        for (j=0;j<m;j++) ma[i][j]-=tval;
    }

    mini = 987654321; t = 0;
    for (j=0;j<m;j++) {
        if (mini>ma[0][j]) {
            mini = ma[0][j];
            t = j;
        }
    }
    for (j=0;j<m;j++) {
        int tval = ma[0][j]-ma[0][t];
        for (i=0;i<tval;i++) {
            row[p] = false;
            ans[p++] = j+1;
        }
        for (i=0;i<n;i++) ma[i][j]-=tval;
    }
    if (n<m) {
        for (i=0;i<n;i++) {
            for (j=0;j<ma[0][0];j++) {
                row[p] = true;
                ans[p++] = i+1;
            }
        }
    }
    else {
        for (j=0;j<m;j++) {
            for (i=0;i<ma[0][0];i++) {
                row[p] = false;
                ans[p++] = j+1;
            }
        }
    }
    printf("%d\n",p);
    for (i=0;i<p;i++) {
        if (row[i]) printf("row ");
        else printf("col ");
        printf("%d\n",ans[i]);
    }

    return 0;
}