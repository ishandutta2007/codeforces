#include<bits/stdc++.h>
using namespace std;
const int N = 100009;
int n,a[19],c[N],tot;
struct pp{int val,id;}p[N*6];
bool cmp(pp x,pp y){return x.val<y.val;}
bool check(int x){
    memset(c,0,sizeof(c));
    int i,j=0,cnt=0;
    for(i=1;i<=tot;i++){
        while(j<tot&&p[j+1].val<=p[i].val+x){
            j++;c[p[j].id]++;
            if(c[p[j].id]==1) cnt++;
        }
        if(cnt==n) return 1;
        c[p[i].id]--;if(!c[p[i].id]) cnt--;
    }
    return 0;
}
int main(){
    for(int i=1;i<=6;i++) scanf("%d",&a[i]);
    scanf("%d",&n);tot=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        for(int j=1;j<=6;j++)
            if(x>a[j]){
                p[++tot].val=x-a[j],p[tot].id=i;
            }
    }
    sort(p+1,p+tot+1,cmp);
    int l=0,r=1e9,ans=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}