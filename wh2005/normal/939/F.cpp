#include<bits/stdc++.h>
using namespace std;
const int M = 109;
const int N = 2e5+9;
const int inf = 1e9;
int n,k,f[2][N],q[N],l,r;
struct pp{int l,r;}a[M];
bool cmp(pp x,pp y){return x.l<y.l;}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=n;i++) f[0][i]=inf;
    f[0][0]=0;
    for(int i=1;i<=k;i++){
        int c=i&1,l=1,r=0;
        memcpy(f[c],f[c^1],sizeof(f[c]));
        for(int j=0;j<=min(n,a[i].r);j++){
            while(l<=r&&f[c^1][j]<=f[c^1][q[r]]) r--;
            while(l<=r&&q[l]<j-(a[i].r-a[i].l)) l++;
            q[++r]=j;
            f[c][j]=min(f[c][j],f[c^1][q[l]]+2);
        }
        l=1,r=0;
        for(int j=a[i].r;j>=0;j--){
            while(l<=r&&f[c^1][a[i].r-j]<=f[c^1][q[r]]) r--;
            while(l<=r&&q[l]<(a[i].l-j)) l++;q[++r]=a[i].r-j;
            f[c][j]=min(f[c][j],f[c^1][q[l]]+1);
        }
    }
    if(f[k&1][n]^inf) printf("Full\n%d\n",f[k&1][n]);
    else printf("Hungry\n");
    return 0;
}