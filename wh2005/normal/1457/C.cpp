#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+9;
int T,n,p,k;ll a,b,f[N];
char s[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&p,&k);scanf("%s",s+1);
        scanf("%lld%lld",&a,&b);
        memset(f,0,sizeof(f));
        for(int i=n;i>=1;i--){
            if(s[i]=='0') f[i]=a;
            f[i]+=f[i+k];
        }
        ll ans=-1;
        for(int i=n;i>=1;i--){
            int pos=i-p+1;if(pos<1) break;
            ll area=1ll*(pos-1)*b+f[i];
            if(ans==-1) ans=area;
            else ans=min(area,ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}