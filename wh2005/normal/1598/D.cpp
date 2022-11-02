#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e6+9;
int T,n,a[N],b[N];
struct pp{int a,b;}p[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) a[i]=0,b[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].a,&p[i].b);
            a[p[i].a]++,b[p[i].b]++;
        }
        ll ans=1ll*n*(n-1)*(n-2)/6;
        for(int i=1;i<=n;i++){
            ans-=1ll*(a[p[i].a]-1)*(b[p[i].b]-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}