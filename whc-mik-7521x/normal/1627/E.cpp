#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+10;
int n,m,k,ax[N],a[N],b[N],c[N],d[N],he[N];
long long dis[N];
struct edge{
    int w,to,nex;
};
edge ed[N<<1];
int cnt,h[N],dep[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
struct node{
    int step,num;
    long long dis;
    bool operator<(const node kk)const{
        return step==kk.step?dis>kk.dis:step>kk.step;
    }
};
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        map<pair<int,int>,int>mp;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=k*3;i++)h[i]=0;
        cnt=0;
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            scanf("%lld",&ax[i]);
        }
        v.push_back({1,1});
        v.push_back({n,m});
        for(int i=1;i<=k;i++){
            scanf("%lld%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i],&he[i]);
            v.push_back({a[i],b[i]});
            v.push_back({c[i],d[i]});
        }
        stable_sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<(int)v.size()-1;i++){
            if(v[i].first==v[i+1].first)add(i+1,i+2,1ll*ax[v[i].first]*(v[i+1].second-v[i].second)),add(i+2,i+1,1ll*ax[v[i].first]*(v[i+1].second-v[i].second));
        }
        for(int i=0;i<(int)v.size();i++)dep[i+1]=v[i].first,mp[v[i]]=i+1,dis[i+1]=-1;
        for(int i=1;i<=k;i++){
            int x=mp[{a[i],b[i]}];
            int y=mp[{c[i],d[i]}];
            add(x,y,-he[i]);
        }
        priority_queue<node>q;
        q.push({1,mp[{1,1}],0});
        while(q.size()){
            node now=q.top();
            q.pop();
            if(dis[now.num]!=-1)continue;
            dis[now.num]=now.dis;
            int u=now.num;
            for(int i=h[u];i;i=ed[i].nex){
                int to=ed[i].to;
                q.push({dep[to],to,now.dis+ed[i].w});
            }
        }
        long long en=dis[mp[{n,m}]];
        if(en==-1)puts("NO ESCAPE");
        else printf("%lld\n",en);
    }
    return  0;
}