#include<bits/stdc++.h>
using namespace std;
const int N = 100009;
#define int long long
int n,l,r,s[N],top;
struct pp{int a,b,h;}c[N];
bool cmp(pp x,pp y){
    return x.b==y.b?(x.a>y.a):(x.b>y.b);
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
        scanf("%lld%lld%lld",&c[i].a,&c[i].b,&c[i].h);
    sort(c+1,c+n+1,cmp);
    int ans=0,sum=0;top=0;
    for(int i=1;i<=n;i++){
        while(top&&c[i].b<=c[s[top]].a) sum-=c[s[top--]].h;
        s[++top]=i,sum+=c[i].h;
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}