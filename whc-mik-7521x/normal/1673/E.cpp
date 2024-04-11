#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10,mod=2;
vector<int>pw[N];
int n,k,ans[N],a[N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=max(0,n-30);i<=n+1;i++){
        pw[i].resize(N);
        pw[i][0]=1;
        for(int o=1;o<i+5;o++){
            pw[i][o]=pw[i][o-1]+((i&o)==o);
            pw[i][o]%=mod;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int sum=0,o=i;o<=n&&sum<=20&&1ll*(1<<sum)*a[i]<1<<20;++o,sum+=a[o]){
            int ch=(n-1)-(o-i)-(i!=1)-(o!=n),kk=max(0,k-(i!=1)-(o!=n)),now=((1<<sum)*a[i]);
            if(ch<kk)continue;
            if(ch==0)ans[now]^=(kk==0);
            else{
                int res=ch==0;
                if(kk!=0)res+=pw[ch][kk-1];
                res%=mod;
                ans[now]^=res;
            }
        }
    }
    int pd=0;
    for(int i=(1<<20)-1;i>=0;i--){
        if(ans[i])pd=1;
        if(pd)printf("%d",ans[i]);
    }
    if(!pd)puts("0");
    return  0;
}