#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
using lli = long long;

lli ans[1000010];
int n,m,w,l[1000010],r[1000010],cost[1000010];
pii arr[1000010];

int main() {
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++) {
        scanf("%d",&m);
        l[0]=-1; r[0]=w-m;
        
        int s=0,f=-1;
        arr[++f] = {0, 0};
        for(int j=1;j<=m;j++) {
            int v;
            scanf("%d",&v);
            cost[j]=v;
            while(s<=f && r[arr[s].se] < j) s++;
            while(s<=f && arr[f].fi <= v) {
                r[arr[f].se] = j-1;
                if(l[arr[f].se] <= r[arr[f].se]) break;
                f--;
            }
            if(s<=f) l[j]=r[arr[f].se]+1;
            else l[j] = j;
            r[j] = w-m+j;

            arr[++f] = {v,j};
        }
        while(s<=f && r[arr[s].se] < m+1) s++;
        while(s<=f && arr[f].fi <= 0) {
            r[arr[f].se] = m;
            if(l[arr[f].se] <= r[arr[f].se]) break;
            f--;
        }
        
        for(int j=1;j<=m;j++) if(l[j]<=r[j]) {
            ans[l[j]]+=cost[j];
            ans[r[j]+1]-=cost[j];
        }
    }
    for(int j=1;j<=w;j++) {
        ans[j]+=ans[j-1];
        printf("%lld ",ans[j]);
    }
    return 0;
}