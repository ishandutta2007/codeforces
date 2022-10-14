#include <bits/stdc++.h>
using namespace std;
const int N=3550;
const int inf=1e9+7;
int a[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,m,k;scanf("%i%i%i",&n,&m,&k);
        k=min(k,m-1);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        int ans=0;
        for(int i=0;i<=k;i++){
            int tmp=inf;
            for(int j=0;j<=m-k-1;j++)tmp=min(tmp,max(a[1+i+j],a[1+i+j+n-m]));
            ans=max(ans,tmp);
        }
        printf("%i\n",ans);
    }
}