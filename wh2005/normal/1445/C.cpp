#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;ll x,y;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&x,&y);
        if(y>x) printf("%lld\n",x);
        else if(x%y!=0){
            printf("%lld\n",x);
        }else{
            ll ans=1;
            for(ll i=2;i*i<=y;i++)
                if(y%i==0){
                    ll pos=0,t=1;
                    while(y%i==0&&y){
                        y/=i,pos++,t*=i;
                    }
                    ll p=x;t/=i;
                    while(p%i==0) p/=i;
                    ans=max(ans,p*t);
                    if(y==1||!y) break;
                }
            if(y&&y>1){
                while(x%y==0&&x) x/=y;
                ans=max(ans,x);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}