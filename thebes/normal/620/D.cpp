#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 2005;
ll N, M, i, j, d, a[MN], b[MN], ans, nxt;
pii id[MN*MN];
map<ll,ll> mp;
vector<pii> sna;

int main(){
    for(scanf("%lld",&N),i=1;i<=N;i++)
        scanf("%lld",&a[i]), d+=a[i];
    for(scanf("%lld",&M),i=1;i<=M;i++)
        scanf("%lld",&b[i]), d-=b[i];
    ans = abs(d);
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            ll dd = d-2*(a[i]-b[j]);
            if(abs(dd)<ans){
                ans = abs(dd);
                sna.clear();
                sna.push_back({j,i});
            }
        }
    }
    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            ll dd = -2*(a[i]+a[j]);
            mp[dd] = ++nxt;
            id[nxt] = {i,j};
        }
    }
    for(i=1;i<=M;i++){
        for(j=i+1;j<=M;j++){
            ll dd = d+2*(b[i]+b[j]);
            if(mp.empty()) continue;
            auto it = mp.lower_bound(-dd);
            auto it2 = it; it2--;
            ll idd=-1, val;
            if(it!=mp.end()&&it2!=mp.end()){
                ll dd1 = dd+it->first;
                ll dd2 = dd+it2->first;
                val = min(abs(dd1), abs(dd2));
                if(abs(dd1)<abs(dd2)) idd=it->second;
                else idd=it2->second;
            }
            else if(it!=mp.end()) idd=it->second, val=abs(dd+it->first);
            else if(it2!=mp.end()) idd=it2->second, val=abs(dd+it2->first);
            if(idd!=-1){
                if(val<ans){
                    ans = val;
                    sna.clear();
                    sna.push_back({i,id[idd].first});
                    sna.push_back({j,id[idd].second});
                }
            }
        }
    }
    printf("%lld\n%d\n",ans,sna.size());
    for(auto v : sna) printf("%d %d\n",v.second,v.first);
    return 0;
}