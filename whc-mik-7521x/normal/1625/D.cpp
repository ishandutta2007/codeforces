#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],b[N],c[N],n,k,kk,vis[N<<6],trie[N<<6][2],cntt;
vector<pair<int,int> >v[N];
vector<int>resu;
map<int,bool>mp[N];
void del(int x){
    int now=x,rt=0;
    for(int i=30;i>=0;i--){
        rt=trie[rt][(now>>i)&1];
        --vis[rt];
    }
}
int ins(int x){
    int now=x,rt=0,res=0;
    for(int i=30;i>=0;i--){
        if(vis[trie[rt][((now>>i)&1)^1]])res+=1<<i,rt=trie[rt][((now>>i)&1)^1];
        else if(vis[trie[rt][(now>>i)&1]])rt=trie[rt][(now>>i)&1];
        else break;
    }
    rt=0;
    for(int i=30;i>=0;i--){
        if(trie[rt][(now>>i)&1])rt=trie[rt][(now>>i)&1];
        else rt=(trie[rt][(now>>i)&1]=++cntt);
        vis[rt]++;
    }
    return res;
}
int calc(int x){
    int mx=0,cnttt=0,now=0;
    for(int i=0;i<(int)v[x].size();i++){
        mx=max(mx,ins(v[x][i].first));
    }
    if(mx>=k){
        for(int i=0;i<(int)v[x].size();i++){
            if(mx==ins(v[x][i].first)){
                if(cnttt<2){
                    if(cnttt==0)resu.push_back(v[x][i].second),cnttt++,now=mx^v[x][i].first;
                    else if(v[x][i].first==now)resu.push_back(v[x][i].second),cnttt++;
                }
            }
        }
        for(int i=0;i<(int)v[x].size();i++){
            del(v[x][i].first);
        }
        for(int i=0;i<(int)v[x].size();i++){
            del(v[x][i].first);
        }
        return 2;
    }
    else{
        for(int i=0;i<(int)v[x].size();i++){
            del(v[x][i].first);
        }
        resu.push_back(v[x][0].second);
        return 1;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<=30;i++)if((1<<i)<=k)kk=i;
    vector<int>u;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]>>(kk+1);
        c[i]=a[i]&((1ll<<(kk+1))-1);
        u.push_back(b[i]);
    }
    if(k==0){
        printf("%d\n",n);
        for(int i=1;i<=n;i++)printf("%d ",i);
        return 0;
    }
    stable_sort(u.begin(),u.end());
    u.erase(unique(u.begin(),u.end()),u.end());
    for(int i=1;i<=n;i++)b[i]=lower_bound(u.begin(),u.end(),b[i])-u.begin();
    int nn=0;
    for(int i=1;i<=n;i++){
        nn=max(nn,b[i]);
        if(!mp[b[i]][c[i]])v[b[i]].push_back({c[i],i}),mp[b[i]][c[i]]=1;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(v[i].size())ans+=calc(i);
    }
    printf("%d\n",ans>1?ans:-1);
    if(ans>1)for(int i=0;i<(int)resu.size();i++)printf("%d ",resu[i]);
    return  0;
}