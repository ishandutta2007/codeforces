#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
int mod=1e9+9;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

vector<int> v[200002];
int chi[202020];

int dfs1(int x,int par){
  int ret=1;
  rep(i,v[x].size()){
    if(v[x][i]==par)continue;
    ret+=dfs1(v[x][i],x);
    }
  return chi[x]=ret;
  }

void dfs2(int x,int par){
  rep(i,v[x].size()){
    if(v[x][i]==par)continue;
    if(chi[v[x][i]]%2==0){
      dfs2(v[x][i],x);
      }
    }
  printf("%d\n",x+1);
  rep(i,v[x].size()){
    if(v[x][i]==par)continue;
    if(chi[v[x][i]]%2==1)dfs2(v[x][i],x);
    }
  }
int main(){
  int n;cin>>n;
  if(n%2==0){
    cout<<"NO"<<endl;
    return 0;
    }
  printf("YES\n");
  rep(i,n){
    int x;
    scanf("%d",&x);
    if(x==0)continue;
    x--;
    v[i].push_back(x);
    v[x].push_back(i);
    }
  dfs1(0,-1);
  dfs2(0,-1);
  return 0;
  }