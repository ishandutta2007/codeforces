#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, sx, sy, cnt;
char str[120][120];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        scanf("%s",str[i]);
        for (j=0;j<m;j++) {
            if (str[i][j]=='B') {
                sx+=i;
                sy+=j;
                cnt++;
            }
        }
    }
    printf("%d %d\n",sx/cnt+1,sy/cnt+1);

    return 0;
}