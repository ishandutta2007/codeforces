//volis li me kad sam mrtav pijan?
//volis li me kad pravi sam grubijan?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
void ckmx(int &x,int y){x=max(x,y);}
int ri(){int x;scanf("%i",&x);return x;}
const int N=300050;
const int inf=1e9+7;
set<pii> all;
int dp[N],l[N],r[N],h[N],ord[N];
int gt(int i,int j){return min(r[i],r[j])-max(l[i],l[j]);}
int main(){
    int n=ri();ri();
    for(int i=1;i<=n;i++){
        h[i]=ri(),l[i]=ri(),r[i]=ri();
        ord[i]=i;
    }
    n++;
    l[0]=l[n]=-inf;l[0]--;
    r[0]=r[n]=inf;r[0]++;
    h[0]=inf;
    ord[n]=n;
    sort(ord+1,ord+1+n,[&](int i,int j){return h[i]>h[j];});
    dp[0]=inf*2;
    all.insert({-inf-5,0});
    all.insert({inf+5,0});
    for(int j=1,i;i=ord[j],j<=n;j++){
        for(auto it=prev(all.upper_bound({l[i],inf}));it->first<r[i];it++){
            auto jt=it;if(jt!=all.begin())jt--;
            auto kt=it;kt++;
            int prv=jt->second;
            int now=it->second;
            int nxt=kt->second;
            if((h[now]<=h[prv] || r[prv]<=max(l[i],l[now])) && (h[now]<=h[nxt] || l[nxt]>=min(r[i],r[now])))ckmx(dp[i],min(dp[now],gt(i,now)));
        }
        auto itl=all.lower_bound({l[i],0});
        auto itr=all.lower_bound({r[i],0});
        int k=prev(itr)->second;
        if(itr->first!=r[i]){ 
            all.insert({r[i],k});
            itl=all.lower_bound({l[i],0});
            itr=all.lower_bound({r[i],0});
        }
        all.erase(itl,itr);
        all.insert({l[i],i});
    }
    printf("%i\n",dp[n]);
    return 0;
}