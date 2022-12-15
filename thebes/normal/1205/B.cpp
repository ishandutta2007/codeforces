#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 1e5+5;
ll n, m, i, j, ans, x, d[MN], cnt[70], id[70], vs[MN];
vi adj[MN], good; vector<pii> e; pii ban; queue<int> q;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld",&x);
        for(j=60;j>=0;j--){
            if((1LL<<j)&x){
                cnt[j]++;
                if(cnt[j]==3){
                    printf("3\n");
                    return 0;
                }
                if(id[j]){
                    adj[id[j]].pb(i);
                    adj[i].pb(id[j]);
                    e.pb({id[j],i});
                    good.pb(id[j]);
                    good.pb(i);
                }
                id[j] = i;
            }
        }
    }
    sort(good.begin(),good.end());
    good.erase(unique(good.begin(),good.end()),good.end());
    ans = 70;
    for(auto ed : e){
        ban = ed;
        for(auto v : good) vs[v]=0;
        d[ed.first] = 0; vs[ed.first] = 1;
        q.push(ed.first);
        while(q.size()){
            int x = q.front(); q.pop();
            for(auto v : adj[x]){
                if(ban==make_pair(v,x)||ban==make_pair(x,v)) continue;
                if(!vs[v]){
                    vs[v] = 1;
                    d[v] = d[x]+1;
                    q.push(v);
                }
            }
        }
        if(vs[ed.second]) ans = min(ans,d[ed.second]+1);
    }
    printf("%lld\n",ans==70?-1:ans);
    return 0;
}