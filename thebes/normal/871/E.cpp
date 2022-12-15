#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back

const int MN = 3e4+5, MM = 202, mod = 1e9+7;
int N, K, i, j, x, y, c, f, w, arr[MN][MM], id[MN], hsh[MN], cc[MN][MM];
map<int,vi> mp; vector<pii> ans; vi res;

int hs(vi vec){
    int r=1;
    for(auto v : vec) r=(1LL*r*(N+1)+v)%mod;
    return r;
}

int main(){
    for(scanf("%d%d",&N,&K),i=1;i<=K;i++){
        w = 0;
        for(j=1;j<=N;j++){
            scanf("%d",&arr[j][i]);
            if(!arr[j][i]) w++, f=i;
        }
        if(w!=1) return !printf("-1\n");
    }
    for(i=1;i<=N;i++){
        hsh[i]=1;
        for(j=1;j<=K;j++)
            hsh[i]=(1LL*hsh[i]*(N+1)+arr[i][j])%mod;
        id[i]=i;
    }
    if(!f) return !printf("-1\n");
    sort(id+1,id+N+1,[](int i,int j){return arr[i][f]>arr[j][f];});
    for(i=1;i<=N;i++){
        if(mp.count(hsh[id[i]])){
            vi wh = mp[hsh[id[i]]];
            for(auto v : wh){
                ans.pb({v,id[i]}), c++;
                for(j=1;j<=K;j++) cc[id[i]][j]|=cc[v][j];
            }
            mp.erase(hsh[id[i]]);
        }
        for(j=1;j<=K;j++) if(!arr[id[i]][j]) cc[id[i]][j]=1;
        res.clear();
        for(j=1;j<=K;j++){
            if(cc[id[i]][j]) res.pb(arr[id[i]][j]+1);
            else res.pb(arr[id[i]][j]-1);
        }
        int hh = hs(res);
        if(!mp.count(hh)) mp[hh]=vi();
        mp[hh].pb(id[i]);
    }
    if(c!=N-1) printf("-1\n");
    else for(auto v : ans) printf("%d %d\n",v.first,v.second);
    return 0;
}