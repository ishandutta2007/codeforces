#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
int mul(int x,int y){return (ll)x*y%mod;}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);return ans;}

const int N=1000050;
ll ans[N];
int a[N],cnt[N],dv[N];
int main() {
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++){
        scanf("%i",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[i]+=cnt[j];
        }
    }
    for(int i=N-1;i>=2;i--){
        if(dv[i]>0){
            ans[i]=mul(dv[i],powmod(2,dv[i]-1));
            for(int j=i+i;j<N;j+=i)ans[i]=sub(ans[i],ans[j]);
        }
    }
    int sum=0;
    for(int i=2;i<N;i++)sum=add(sum,mul(i,ans[i]));
    printf("%i",sum);
    return 0;
}