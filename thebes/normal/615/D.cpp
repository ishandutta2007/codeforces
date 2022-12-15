#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5, mod = 1e9+7;
int n, i, x, cnt[MN], suf[MN], tot=1, ans=1;
int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    suf[MN-1] = 1;
    for(i=MN-2;i>=1;i--)
        suf[i]=1LL*suf[i+1]*(cnt[i]+1)%(mod-1);
    for(i=1;i<MN-2;i++){
        tot=1LL*tot*(cnt[i]+1)%(mod-1);
        int coef = (1LL*cnt[i+1]*(cnt[i+1]+1)/2)%(mod-1);
        ans=1LL*ans*qpow(i+1,1LL*tot*suf[i+2]%(mod-1)*coef%(mod-1))%mod;
    }
    printf("%d\n",ans);
    return 0;
}