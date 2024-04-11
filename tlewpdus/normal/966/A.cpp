#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, vv;

int st[100100];
int el[100100];

int dis(int x, int y, int n, int st[]) {
    int i, mini = 1e9+10;
    int t = (upper_bound(st,st+n,x)-st);
    if (t<n) mini = min(mini,abs(st[t]-x)+abs(st[t]-y));
    t--;
    if (t>=0) mini = min(mini,abs(st[t]-x)+abs(st[t]-y));
    return mini;
}

int main() {
    int i;

    scanf("%d%d%d%d%d",&n,&m,&a,&b,&vv);
    for (i=0;i<a;i++) scanf("%d",&st[i]);
    for (i=0;i<b;i++) scanf("%d",&el[i]);
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        int t, s, u, v;
        scanf("%d%d%d%d",&t,&s,&u,&v);
        if (t==u) {
            printf("%d\n",abs(v-s));
        }
        else {
            printf("%d\n",min(dis(s,v,a,st)+abs(t-u),dis(s,v,b,el)+(abs(t-u)+vv-1)/vv));
        }
    }

    return 0;
}