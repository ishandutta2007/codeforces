#include <bits/stdc++.h>

using namespace std;

int n,m,a[50][50],ta[50];

void mswap(int type,int i1,int j1,int i2,int j2){
    if (type==1) swap(ta[i2],ta[j2]);
    swap(ta[i1],ta[j1]);
    if (type==0) swap(ta[i2],ta[j2]);
}
bool check(int row,int c1,int c2,int type){
    for(int i=1;i<=m;i++) ta[i]=a[row][i];
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++){
            mswap(type,i,j,c1,c2);
            for(int k=1;k<=m;k++){
                if (ta[k]!=k) break;
                if (k==m) return 1;
            }
            mswap(type^1,i,j,c1,c2);
        }
    return 0;
}
bool check(int c1,int c2){
    for(int i=1;i<=n;i++)
        if (!check(i,c1,c2,0)&&!check(i,c1,c2,1)) return 0;
    printf("YES");
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",a[i]+j);
    for(int c1=1;c1<=m;c1++)
        for(int c2=c1;c2<=m;c2++) if (check(c1,c2)) return 0;
    printf("NO");
}