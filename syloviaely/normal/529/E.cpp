#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
int n,x[6000],q,k;
unordered_map<int,int>M;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        for (int j=1;j<=k;j++){
            int k1=x[i]*j; if (M[k1]==0) M[k1]=j; else M[k1]=min(M[k1],j);
        }
    }
    scanf("%d",&q);
    for (;q;q--){
        int ans=1e9; int k1; scanf("%d",&k1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)
                if (x[i]*j==k1) ans=min(ans,j);
                else {
                    int k2=k1-x[i]*j,k3=M[k2];
                    if (k3&&k3+j<=k) ans=min(ans,j+k3);
                }
        if (ans<=k) printf("%d\n",ans); else printf("-1\n");
    }
    return 0;
}