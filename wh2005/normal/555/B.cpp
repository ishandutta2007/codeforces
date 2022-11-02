#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>

using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAXN=1e6+7;
pll W[MAXN];
ll a[MAXN];
int n,m,k;
vector<pii> vec[MAXN];
vector<int> ins[MAXN];
void lsh(){
    vector<ll> id;
    id.reserve(2*n+m);
    for(ri i=2;i<=n;++i){
        id.push_back(W[i].first-W[i-1].second);
        id.push_back(W[i].second-W[i-1].first);
    }
    for(ri i=1;i<=m;++i) id.push_back(a[i]);
    sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
    k=id.size();
    for(ri i=2;i<=n;++i){
        int l=lower_bound(id.begin(),id.end(),W[i].first-W[i-1].second)-id.begin()+1,
            r=lower_bound(id.begin(),id.end(),W[i].second-W[i-1].first)-id.begin()+1;
        vec[r].push_back((pii){l,i-1});
    }
    for(ri i=1;i<=m;++i) a[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin()+1,ins[a[i]].push_back(i);
}
set<pii> s;
int ans[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    for(ri i=1;i<=n;++i) scanf("%lld%lld",&W[i].first,&W[i].second);
    for(ri i=1;i<=m;++i) scanf("%lld",&a[i]);
    lsh();
    for(ri i=1;i<=k;++i){
        for(auto x:ins[i]) s.insert((pii){i,x});
        for(auto x:vec[i]){
            if(s.empty()||s.rbegin()->first<x.first) return puts("No");
            auto it=s.upper_bound((pii){x.first,0});
            ans[x.second]=it->second;
            s.erase(it);
        }
    }
    puts("Yes");
    for(ri i=1;i<n;++i) printf("%d ",ans[i]);
}