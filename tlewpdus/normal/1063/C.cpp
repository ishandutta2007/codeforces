#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char buf[20];
char st[3] = "wb";

int main() {
    int i;

    scanf("%d",&n);
    int l = 1, r = 1e9;
    printf("0 1\n");
    fflush(stdout);
    scanf("%s",buf);
    if (buf[0]=='w') st[0] = 'b', st[1] = 'w';
    for (i=1;i<n;i++) {
        int m = (l+r)/2;
        printf("%d 1\n",m); fflush(stdout);
        scanf("%s",buf);
        int t;
        for (t=0;t<2;t++) if (st[t]==buf[0]) break;
        if (t) l = m+1;
        else r = m-1;
    }
    printf("%d 2 %d 0\n",l,l-1);

    return 0;
}