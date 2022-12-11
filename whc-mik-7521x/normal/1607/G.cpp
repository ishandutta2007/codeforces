#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,m,a[N],b[N],l[N],r[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        long long sum=0,ans=0;
        long long ll=0,rr=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
            sum+=a[i]-b[i];
            if(a[i]>=m)r[i]=m;
            else r[i]=a[i]-((m-a[i]));
            if(b[i]>=m)l[i]=-m;
            else l[i]=-(b[i]-((m-b[i])));
            ll+=l[i],rr+=r[i];
        }
        if(ll>sum)ans=ll-sum,sum=ll;
        else if(rr<sum)ans=sum-rr,sum=rr;
        else ans=((sum-ll)&1);
        long long now=((sum-ll)|1)^1;
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++){
            int mx=r[i]-l[i];
            if(now>=mx){
                now-=mx;
                printf("%d %d\n",(r[i]+m)>>1,(m-r[i])>>1);
            }
            else if(now){
                int kk=l[i]+now;
                now=0;
                printf("%d %d\n",(m+kk)>>1,(m-kk)>>1);
            }
            else{
                printf("%d %d\n",(l[i]+m)>>1,(m-l[i])>>1);
            }
        }
    }
    return  0;
}