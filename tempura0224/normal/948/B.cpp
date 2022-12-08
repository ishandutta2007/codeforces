#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

vector<int> p;

int mp(int n){
  int ret=1;
  rep(i,p.size()){
    if(n==1)break;
    if(n%p[i]==0){
      ret=p[i];
      while(n%p[i]==0){
        n/=p[i];
        }
      }
    }
   return max(ret,n);
  }
    

int main(){
  int n=1000001;
  bool isprime[n];
  rep(i,n)isprime[i]=true;
  isprime[0]=isprime[1]=false;
  for(int i=2;i*i<n;i++){
    if(isprime[i]){
      for(int j=2;i*j<n;j++)
        isprime[i*j]=false;
      }
    }
  rep(i,1001)if(isprime[i])p.push_back(i);
  int m;cin>>m;
  int r=mp(m);
  int ans=inf;
  rep(i,r){
    int tmp=m-i;
    if(!isprime[tmp])ans=min(ans,tmp-mp(tmp)+1);
    }
  cout<<ans<<endl;
  return 0;
  }