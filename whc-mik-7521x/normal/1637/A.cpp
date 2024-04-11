#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],mx[N],mi[N],n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        mx[0]=0;
        for(int i=1;i<=n;i++){
            mx[i]=max(mx[i-1],a[i]);
        }
        mi[n+1]=1e9+7;
        for(int i=n;i>=1;i--){
            mi[i]=min(mi[i+1],a[i]);
        }
        bool pd=0;
        for(int i=1;i<=n;i++){
            if(mx[i-1]>mi[i])pd=1;
        }
        puts(pd?"YES":"NO");
    }
    return  0;
}