#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int op[1010101],a[1010101];
int v[1010101][2];

int dfs1(int x){
  if(op[x]==0)return a[x];
  if(op[x]==1)return a[x]=1-dfs1(v[x][0]);
  if(op[x]==2)return a[x]=dfs1(v[x][0])&dfs1(v[x][1]);
  if(op[x]==3)return a[x]=dfs1(v[x][0])^dfs1(v[x][1]);
  if(op[x]==4)return a[x]=dfs1(v[x][0])|dfs1(v[x][1]);
  return 0;
}

bool change[1010101];
void dfs2(int x,bool p){
  change[x]=p;
  if(p==0)return;
  if(op[x]==0)return;
  if(op[x]==1)dfs2(v[x][0],p);
  else {
      if(op[x]==2){
        dfs2(v[x][0],a[v[x][1]]),dfs2(v[x][1],a[v[x][0]]);
      }
      if(op[x]==3){
        dfs2(v[x][0],1),dfs2(v[x][1],1);
      }
      if(op[x]==4){
        dfs2(v[x][0],1-a[v[x][1]]),dfs2(v[x][1],1-a[v[x][0]]);
      }
    }
}
int main(){
   int n;cin>>n;
   rep(i,n){
     string s;cin>>s;
     if(s=="IN"){
       op[i]=0;
       scanf("%d",&a[i]);
   }
   if(s=="NOT"){
     op[i]=1;
     scanf("%d",&v[i][0]);
     v[i][0]--;
   }
   if(s=="AND"){
     op[i]=2;
     scanf("%d%d",&v[i][0],&v[i][1]);
     v[i][0]--;v[i][1]--;
   }
   if(s=="XOR"){
     op[i]=3;
     scanf("%d%d",&v[i][0],&v[i][1]);
     v[i][0]--;v[i][1]--;
   }
   if(s=="OR"){
     op[i]=4;
     scanf("%d%d",&v[i][0],&v[i][1]);
     v[i][0]--;v[i][1]--;
   }
  }
  int ret=dfs1(0);
  dfs2(0,1);
  rep(i,n)if(op[i]==0)printf("%d",ret^change[i]);
  cout<<endl;
  return 0;
}