#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int C;
struct node{
    int c,d,h;
    bool operator<(const node b)const{
        return 1ll*h*d*b.c>1ll*b.h*b.d*c;
    }
}ty[N];
long long dmg[N];
int n,m;
int main(){
    scanf("%d%d",&n,&C);
    for(int i=1;i<=n;i++){
        int c,d,h;
        scanf("%d%d%d",&c,&d,&h);
        dmg[c]=max(dmg[c],1ll*d*h);
    }
    for(int i=1;i<=C;i++){
        for(int o=i;o<=C;o+=i)dmg[o]=max(dmg[o],dmg[i]*o/i);
    }
    for(int i=1;i<=C;i++)dmg[i]=max(dmg[i],dmg[i-1]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        long long D,H;
        scanf("%lld%lld",&D,&H);
        D*=H;
        int ans=upper_bound(dmg+1,dmg+C+1,D)-dmg;
        printf("%d ",ans==C+1?-1:ans);
    }
    return  0;
}