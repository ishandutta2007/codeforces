#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;
int t,n,a[N],dp1[N],dp2[N],dp3[N],dp4[N];
struct BIT{
    int ts[N];
    int ask(int x){
        int res=0;
        for(;x;x-=x&-x)res+=ts[x],res%=mod;
        return res;
    }
    void add(int x,int d){
        for(;x<=n;x+=x&-x)ts[x]+=d,ts[x]%=mod;
    }
    void init(){
        for(int i=0;i<=n;i++)ts[i]=0;
    }
};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int>v;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            v.push_back(a[i]);
        }
        stable_sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=1;i<=n;i++){
            a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        }
        BIT t1,t2,t3,t4;
        t1.init();
        t2.init();
        t3.init();
        t4.init();
        for(int i=1;i<=n;i++){
            dp1[i]=(t1.ask(a[i]-1)+1+mod)%mod;
            t1.add(a[i],dp1[i]);
        }
        for(int i=n;i>=1;i--){
            dp2[i]=(t2.ask(n)-t2.ask(a[i])+1+mod)%mod;
            t2.add(a[i],dp2[i]);
        }
        vector<int>u;
        int pd[N];
        for(int i=1;i<=n;i++)pd[i]=0;
        for(int i=n;i>=1;i--){
            if(!u.size()||a[i]>=u.back())u.push_back(a[i]),pd[i]=1;
        }
        // for(int i=1;i<=n;i++){
        //     int now=lower_bound(u.begin(),u.end(),a[i])-u.begin();
        //     if(!now){
        //         dp3[i]=t3.ask(a[i]-1)+1;
        //         dp3[i]%=mod;
        //         t3.add(a[i],dp3[i]);
        //     }
        //     else{
        //         dp3[i]=t3.ask(a[i]-1)-t3.ask(u[now-1]-1)+1;
        //         dp3[i]%=mod;
        //         t3.add(a[i],dp3[i]);
        //     }
        // }
        for(int i=n;i>=1;i--){
            if(pd[i]){
                dp4[i]=1;
            }
            else{
                int now=upper_bound(u.begin(),u.end(),a[i])-u.begin();
                dp4[i]=(t4.ask(u[now]-1)-t4.ask(a[i])+1+mod)%mod;
                t4.add(a[i],dp4[i]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=((1ll*dp1[i]*dp2[i]+ans)%mod+mod)%mod;
        }
        for(int i=1;i<=n;i++){
            ans=((ans*1ll-1ll*dp1[i]*dp4[i])%mod+mod)%mod;
        }
        printf("%d\n",ans);
    }
    return  0;
}