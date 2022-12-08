#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;

int dp[101][101][27];
vector<pint> v[5001];

bool dfs(int fi,int se,int ch){
  if(dp[fi][se][ch]!=-1) return dp[fi][se][ch];
  int ret=0;
  rep(i,v[fi].size()){
    if(v[fi][i].second>=ch){
      if(dfs(se,v[fi][i].first,v[fi][i].second)==0){
        ret=1;
        break;
        }
      }
    }
  return dp[fi][se][ch]=ret;
  }

int main(){
  int n,m;
  cin>>n>>m;
  rep(i,m){
    int l,r;
    char c;
    cin>>l>>r>>c;
    int ch=c-'a';
    l--;r--;
    v[l].push_back(pint(r,ch+1));
    }
  rep(i,n)rep(j,n)rep(k,27)
    dp[i][j][k]=-1;
  rep(i,n){
    rep(j,n){
      if(dfs(i,j,0))cout<<"A";
      else cout<<"B";
      }
    cout<<endl;
    }
  return 0;
  }