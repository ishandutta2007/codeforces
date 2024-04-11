#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,a[N];

int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<30;i++){
            int p=0;
            for(int j=1;j<=n;j++) if((a[j]>>i)&1) p++;
            ans=gcd(ans,p);
        }
        if(!ans){
            for(int i=1;i<=n;i++) printf("%d ",i);puts("");
        }
        else{
            for(int i=1;i<=n;i++){
                if(ans%i==0) printf("%d ",i);
            }
            puts("");
        }
    }
    return 0;
}