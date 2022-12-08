#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<int,pint> p3;
const int inf   = 1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

struct BIT{
  int sz;
  vector<int> dat;
  BIT(int n,int init){
    sz=n;
    rep(i,n+1)dat.push_back(init);
    }
  
  void update(int k,int x){
    while(k<=sz){
      dat[k]=max(dat[k],x);
      k+=k&(-k);
      }
    }
  
  int get(int k){
    int ret=0;
    while(k>0){
      ret=max(ret,dat[k]);
      k-=k&(-k);
      }
    return ret;
    }
  
  };


int main(){
  int n;
  scanf("%d",&n);
  p3 w[n];
  int a[n],b[n],c[n];
  rep(i,n)scanf("%d",&a[i]);
  rep(i,n)scanf("%d",&b[i]);
  rep(i,n)scanf("%d",&c[i]);
  rep(i,n)w[i]={-a[i],{b[i],c[i]}};
    
  sort(b,b+n);
  map<int,int> mp;
  rep(i,n){
    mp[b[i]]=n-i;
    }
  sort(w,w+n);
  BIT bit(n,0);
  int ans=0;
  rep(i,n){
    if(bit.get(mp[w[i].second.first]-1)>w[i].second.second){
      ans++;
      }
    else bit.update(mp[w[i].second.first],w[i].second.second);
    }
  cout<<ans<<endl;                      
  return 0;
  }