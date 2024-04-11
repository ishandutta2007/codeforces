#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n[N],dg[N];
vector<int>v[N];
vector<int>ans[N];
vector<int>u;
struct edge{
    int nm,ct,to;
    bool operator<(const edge b)const{
        return ((nm==b.nm)?((ct==b.ct)?(to<b.to):(ct<b.ct)):(nm<b.nm));
    }
};
multiset<edge>ed[N];
void add(int s,int e,int nm,int ct){
    // cout<<s<<' '<<e<<' '<<nm<<' '<<ct<<endl;
    ed[s].insert((edge){nm,ct,e});
    dg[s]++;
}
void dfs(int x){
    if(!dg[x])return;
    edge now=*ed[x].begin();
    ed[x].erase(ed[x].begin());
    ans[now.nm][now.ct]=1;
    dg[x]--,dg[now.to]--;
    // cout<<now.nm<<' '<<now.ct<<endl;
    ed[now.to].erase(ed[now.to].find((edge){now.nm,now.ct&1?now.ct+1:now.ct-1,x}));
    dfs(now.to);
}
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&n[i]);
        v[i].resize(n[i]+5);
        ans[i].resize(n[i]+5);
        for(int o=1;o<=n[i];o++){
            scanf("%d",&v[i][o]);
            u.push_back(v[i][o]);
        }
    }
    stable_sort(u.begin(),u.end());
    u.erase(unique(u.begin(),u.end()),u.end());
    for(int i=1;i<=m;i++){
        for(int o=1;o<=n[i];o++){
            v[i][o]=lower_bound(u.begin(),u.end(),v[i][o])-u.begin()+1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int o=1;o<=n[i];o+=2){
            add(v[i][o],v[i][o+1],i,o);
            add(v[i][o+1],v[i][o],i,o+1);
        }
    }
    int pd=0;
    for(int i=1;i<N;i++)if(dg[i]%2!=0)pd=1;
    if(pd)puts("NO");
    else{
        puts("YES");
        for(int i=1;i<N;i++)while(dg[i])dfs(i);
        for(int i=1;i<=m;i++){
            for(int o=1;o<=n[i];o++){
                putchar(ans[i][o]?'R':'L');
            }
            puts("");
        }
    }
    return  0;
}