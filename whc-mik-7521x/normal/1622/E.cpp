#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,kk[N];
int pop_count(int x){
    int res=0;
    while(x){res++,x-=x&-x;}
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&kk[i]);
        }
        int mk[N],ans[N];
        long long an=-1e18;
        for(int i=1;i<=m;i++)mk[i]=0;
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                int x;
                scanf("%1d",&x);
                mk[o]=mk[o]<<1|x;
            }
        }
        for(int i=0;i<(1<<n);i++){
            pair<int,int>mx[N];
            // cout<<i<<endl;
            for(int o=1;o<=m;o++){
                mx[o].first=0;
                mx[o].second=o;
                // cout<<mx[o].first<<' '<<o<<endl;
                for(int j=1;j<=n;j++){
                    if(mk[o]&(1<<(j-1))){
                        mx[o].first+=(i&(1<<(j-1)))?1:-1;
                    }
                }
            }
            sort(mx+1,mx+m+1);
            long long tot=0;
            int now[N];
            for(int o=1;o<=m;o++){
                now[mx[o].second]=o;
            }
            for(int o=1;o<=n;o++){
                long long num=0;
                for(int j=1;j<=m;j++){
                    if(mk[j]&(1<<(n-o)))num+=now[j];
                }
                tot+=abs(kk[o]-num);
            }
            if(tot>an){
                an=tot;
                for(int o=1;o<=m;o++){
                    ans[mx[o].second]=o;
                }
            }
        }
        for(int i=1;i<=m;i++)printf("%d ",ans[i]);
        puts("");
    }
    return  0;
}