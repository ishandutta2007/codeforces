#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
int cnt[N+10][20];
int t;
void init(){
    for(int i=1;i<=N;i++){
        for(int o=0;o<20;o++){
            cnt[i][o]=cnt[i-1][o]+(!!(i&(1<<o)));
        }
    }
}
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        int tot=r-l+1,ans=0,ct[20];
        memset(ct,0,sizeof ct);
        for(int i=1;i<=tot;i++){
            int x;
            scanf("%d",&x);
            for(int o=0;o<20;o++)ct[o]+=!!(x&(1<<o));
        }
        for(int i=0;i<20;i++){
            if(cnt[r][i]-(l?cnt[l-1][i]:0)==tot-ct[i])ans|=(1<<i);
        }
        printf("%d\n",ans);
    }
    return  0;
}