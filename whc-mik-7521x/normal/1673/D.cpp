#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int t,b,q,y,c,r,z;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&b,&q,&y,&c,&r,&z);
        long long ed1=1ll*(y-1)*q+b,ed2=1ll*(z-1)*r+c;
        if(b<=c&&ed1>=ed2){
            if((c-b)%q)puts("0");
            else{
                if(r%q)puts("0");
                else{
                    if(c-r<b||ed2+r>ed1)puts("-1");
                    else{
                        long long ans=0;
                        int kk=r/q;
                        vector<int>fac;
                        for(int i=1;i*i<=q;i++){
                            if(!(q%i)){if(i*i==q)fac.push_back(i);else fac.push_back(i),fac.push_back(q/i);}
                        }
                        for(int i:fac){
                            if(__gcd(kk,q/i)!=1)continue;
                            long long now=kk*i;
                            ans+=1ll*(r/now)*(r/now)%mod;
                            ans%=mod;
                        }
                        printf("%lld\n",ans);
                    }
                }
            }
        }
        else puts("0");
    }
    return  0;
}