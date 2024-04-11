#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
#define endl "\n"
#define MP make_pair
#define fi first
#define se second
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
int main(){

  ll t;cin>>t;
  while(t--){
    ll n,m;cin>>n>>m;
    vector<vector<int>>g(n);
    rep(i,0,m){
      int u,v;cin>>u>>v;u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto bfs=[&](int s){
      vector<int>d(n,-1);
      queue<int>que;
      que.push(s);
      d[s]=0;
      while(!que.empty()){
        auto v=que.front();
        que.pop();
        for(auto to:g[v]){
          if(d[to]==-1){
            que.push(to);
            d[to]=d[v]+1;
          }
        }
      }
      return d;
    };
    auto d0=bfs(0);
    int f;cin>>f;
    vector<int>h(f);
    rep(i,0,f)cin>>h[i],h[i]--;
    int k;cin>>k;
    vector<int>p(k);
    vector<bool>ng(f);
    rep(i,0,k){
      cin>>p[i];
      ng[p[i]-1]=true;
      p[i]=h[p[i]-1];
    }
    sort(ALL(p),[&](int i,int j){return d0[i]<d0[j];});
    vector<vector<int>>d(k);
    rep(i,0,k)d[i]=bfs(p[i]);
    vector<bool>dp(1<<k,false);
    dp[0]=true;
    rep(i,0,f){
      if(ng[i])continue;
      vector<int>v;
      rep(j,1,1<<k){
        int pre=-1;
        int sum=0;
        rep(o,0,k){
          if(~j>>o&1)continue;
          if(pre==-1)sum+=d0[p[o]];
          else sum+=d[pre][p[o]];
          pre=o;
        }
        sum+=d[pre][h[i]];
        if(sum==d0[h[i]]){
          ///cout<<i spa j<<endl;
          v.push_back(j);
        }
      }

      rrep(j,0,1<<k){
        for(auto z:v){
          if(dp[j])dp[j|z]=true;
        }
      }
    }
    ll ret=k;
    rep(i,0,1<<k){
      if(dp[i])chmin(ret,k-__builtin_popcount(i));
    }
    cout<<ret<<endl;
  }

  return 0;
}