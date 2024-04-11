#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e6+9;
int n,m,k,a[N],mp[N];
int bl[N],unit;
struct Ques{int l,r,ans,id;}q[N];
bool cmp(Ques x,Ques y){
    return bl[x.l]==bl[y.l]?(bl[x.r]<bl[y.r]):(bl[x.l]<bl[y.l]);
}
bool cmpp(Ques x,Ques y){return x.id<y.id;}
signed main(){
    memset(a,0,sizeof(a));memset(mp,0,sizeof(mp));
    scanf("%lld%lld%lld",&n,&m,&k);unit=sqrt(n);
    for(int i=1;i<=n;i++){scanf("%lld",&a[i]);a[i]^=a[i-1];}
    for(int i=1;i<=n;i++) bl[i]=(i-1)/unit+1;
    for(int i=1;i<=m;i++){scanf("%lld%lld",&q[i].l,&q[i].r);q[i].id=i;q[i].l-=1;}
    sort(q+1,q+m+1,cmp);
    int l=1,r=0,Ans=0;
    for(int i=1;i<=m;i++){
        while(l<q[i].l) Ans-=mp[a[l]^k],mp[a[l++]]--;
        while(l>q[i].l) mp[a[--l]]++,Ans+=mp[a[l]^k];
        while(r>q[i].r) Ans-=mp[a[r]^k],mp[a[r--]]--;
        while(r<q[i].r) mp[a[++r]]++,Ans+=mp[a[r]^k];
        q[i].ans=Ans;if(!k) q[i].ans-=(r-l+1);
    }
    sort(q+1,q+m+1,cmpp);
    for(int i=1;i<=m;i++) printf("%lld\n",q[i].ans);
    return 0;
}