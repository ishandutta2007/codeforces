#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        long long ans=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x==0)ans+=i*(n-i+1);
        }
        for(int i=1;i<=n;i++)ans+=i*(n-i+1);
        printf("%lld\n",ans);
    }
    return  0;
}