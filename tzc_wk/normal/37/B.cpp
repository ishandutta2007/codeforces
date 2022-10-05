#include <bits/stdc++.h>
using namespace std;
int n,x,y,t[1010],id[1010],vis[1010];
struct node{
    int id, p, d;
}a[1010];
bool cmp1(node a,node b){return a.d>b.d;}
bool cmp2(node a,node b){return a.id<b.id;}
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].p,&a[i].d);
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp1);
    int now=x,d=0,be=0,cnt=0;
    for(int i=0;;i++){
        now -= d; now += y;
        now = min(now, x);
        if(now<=0){
            printf("YES\n%d %d\n",i,cnt);
            for(int j=0;j<cnt;j++) printf("%d %d\n",t[j],id[j]);
            return 0;
        }
        for(int j=1;j<=n;j++){
            if(vis[j]||a[j].p*x<now*100) continue;
            vis[j] = 1; d += a[j].d;
            t[cnt] = i; id[cnt++] = a[j].id;
            break;
        }
        if(be==d&&d<=y) break;
        be = d;
    }
    printf("NO\n");
    return 0;
}