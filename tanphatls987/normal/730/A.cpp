#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;
int n,a[N],ans[N*N][N],b[N];
int check(int val){
    for(int i=1;i<=n;i++) b[i]=a[i]-val;
    if (val==0){
        int n1=0;
        for(int i=2;i<=n;i++){
            while (b[i]){
                b[i]--,b[1]--;
                ++n1;
                ans[n1][1]=ans[n1][i]=1;
            }
        }
        for(int i=b[1];i>=1;i--) {
            ++n1;
            ans[n1][1]=ans[n1][2]=1;
        }
        return n1;
    }
    int sum=0,boss=*max_element(b+1,b+n+1);
    for(int i=1;i<=n;i++) sum+=b[i];
    if (boss>sum-boss) return -1;
    memset(ans,0,sizeof(ans));
    int n1=sum/2;
    for(int pha=1;pha<=n1;pha++){
        int use1=max_element(b+1,b+n+1)-b;
        int use2=0;
        for(int i=1;i<=n;i++) if (i!=use1&&b[i]>b[use2]) use2=i;
        ans[pha][use1]=ans[pha][use2]=1;
        b[use1]--,b[use2]--;
        if (pha==n1&&sum&1){
            for(int use3=1;use3<=n;use3++) if (b[use3]){
                ans[pha][use3]=1;
                b[use3]--;
            }
        }
    }
    return n1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    int val=*min_element(a+1,a+n+1);
    while (check(val)==-1) val--;
    int nans=check(val);
    printf("%d\n%d\n",val,nans);
    for(int i=1;i<=nans;i++){
        for(int j=1;j<=n;j++) printf("%d",ans[i][j]);
        printf("\n");
    }
}