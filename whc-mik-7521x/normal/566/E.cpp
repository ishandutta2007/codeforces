#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bitset<N>st[N],fr[N],ne[N];
int n,pd[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int o=1;o<=k;o++){
            int x;
            scanf("%d",&x);
            st[i][x]=1;
        }
    }
    if(n==2)return puts("1 2"),0;
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++){
        ne[i][i]=1;
        for(int o=i+1;o<=n;o++){
            auto it=st[i]&st[o];
            if(it.count()==2){
                int kk=it._Find_first(),kp=it._Find_next(kk);
                pd[kk]=pd[kp]=1;
                ne[kk][kp]=ne[kp][kk]=1;
                ans.push_back({kk,kp});
            }
        }
    }
    int cnt=0;
    vector<int>vec;
    for(int i=1;i<=n;i++){
        if(pd[i])cnt++;
        else vec.push_back(i);
    }
    if(cnt==0){
        for(int i=2;i<=n;i++)printf("1 %d\n",i);
        return 0;
    }
    if(cnt==2){
        bitset<N>it1,it2;
        for(int i=1;i<=n;i++){
            if(st[i].count()!=n){
                it1=st[i];
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(st[i].count()!=n&&st[i]!=it1){
                it2=st[i];
                break;
            }
        }
        int x=ans[0].first,y=ans[0].second;
        printf("%d %d\n",x,y);
        for(int i=1;i<=n;i++){
            if(i==x||i==y)continue;
            if(it1[i])printf("%d %d\n",x,i);
        }
        for(int i=1;i<=n;i++){
            if(i==x||i==y)continue;
            if(it2[i])printf("%d %d\n",y,i);
        }
        return 0;
    }
    for(int i:vec){
        bitset<N>it;
        int ct=1e9;
        for(int o=1;o<=n;o++){
            if(st[o][i]&&st[o].count()<ct)ct=st[o].count(),it=st[o];
        }
        for(int o=1;o<=n;o++)if(!pd[o])it[o]=0;
        for(int o=1;o<=n;o++){
            if(pd[o]){
                if(it==ne[o]){ans.push_back({i,o});break;}
            }
        }
    }
    stable_sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(auto [x,y]:ans)printf("%d %d\n",x,y);
    return  0;
}