#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>msk;
int t,n;
int solve(int x,int y,const int *cnt){
    int i,tot=0,res=0;
    for(i=1;i<=n;i++){
        if(tot+cnt[i]>x)break;
        tot+=cnt[i];
    }
    res+=x-tot;
    tot=0;
    for(;i<=n;i++){
        if(tot+cnt[i]>y)break;
        tot+=cnt[i];
    }
    res+=y-tot;
    tot=0;
    for(;i<=n;i++)tot+=cnt[i];
    return res+*lower_bound(msk.begin(),msk.end(),tot)-tot;
}
int main(){
    for(int i=0;i<=30;i++)msk.push_back(1<<i);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt[N];
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        int ans=1e9;
        for(int i=0;i<30;i++){
            for(int o=0;o<30;o++){
                ans=min(ans,solve(msk[i],msk[o],cnt));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}