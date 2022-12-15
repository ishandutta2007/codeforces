#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 23, MM = 1e7+6;
int n, m, msk[MN], a[MN], i, j, f, x, y, cnt[MM], ans=MN, hm, lg[MM];

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y); x--; y--;
        msk[x] |= (1<<y);
        msk[y] |= (1<<x);
    }
    for(i=0;i<n;i++) msk[i]|=(1<<i);
    for(i=1;i<MM;i++) cnt[i]=cnt[i-(i&-i)]+1;
    for(i=0;i<n;i++) lg[1<<i]=i;
    for(m=0;m<(1<<n);m++){
        if(cnt[m]>=ans) continue;
        for(i=0;i<n;i++) a[i]=msk[i];
        for(i=0;i<n;i++){
            if(!((1<<i)&m)) continue;
            for(j=a[i];j;j-=j&-j)
                a[lg[j&-j]]|=a[i];
        }
        f=0;
        for(i=0;i<n;i++){
            if(a[i]!=(1<<n)-1){
                f = 1;
                break;
            }
        }
        if(!f) ans=cnt[m], hm=m;
    }
    printf("%d\n",ans);
    for(i=0;i<n;i++){
        if(hm&(1<<i)) printf("%d ",i+1);
    }
    printf("\n");
    return 0;
}