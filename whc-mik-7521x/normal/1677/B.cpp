#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t;
int n,m,r[N],c[N],a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        n=n*m;
        int tot=0;
        for(int i=1;i<=n;i++){
            scanf("%1d",&a[i]);
            a[i]+=a[i-1];
            i>m?r[i]=r[i-m]+(a[i]!=a[i-m]):r[i]=a[i]!=0;
            i>m?(c[i-m]?c[i]=c[i-m]:(a[i]!=a[i-1]?tot++,c[i]=1:c[i]=0)):(a[i]!=a[i-1]?tot++,c[i]=1:c[i]=0);
            printf("%d ",tot+r[i]);
        }
        puts("");
    }
    return  0;
}