#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;

int n;
vector<int> v[100001];
int dist[100001];

void dfs(int x){
  rep(i,v[x].size()){
    int next=v[x][i];
    dist[next]=dist[x]+1;
    dfs(next);
    }
  }

  
int main(){
  cin>>n;
  rep(i,n-1){
    int a;cin>>a;
    v[a-1].push_back(i+1);
    }
  dist[0]=0;
  dfs(0);
  bool cnt[n];
  rep(i,n)cnt[i]=false;
  rep(i,n){
    cnt[dist[i]]=!cnt[dist[i]];
    }
  int ans=0;
  rep(i,n)if(cnt[i])ans++;
  cout<<ans<<endl;
  return 0;
  }