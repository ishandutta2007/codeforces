#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int x[3],y[3];
  for(int i=0;i<3;i++){
    cin >> x[i] >> y[i];
  }
  int tmp;
  int d1=1000000,d2=1000000,ax,ay,b;
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=1000;j++){
      tmp=1;
      for(int k=0;k<3;k++){
        tmp+=abs(x[k]-j)+abs(y[k]-i);
      }
      if(d1>tmp){
        d1=tmp;
        ax=j,ay=i;
      }
    }
  }
  for(int i=0;i<3;i++){
    tmp=1;
    for(int j=0;j<3;j++){
      tmp+=abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
    if(d2>tmp){
      d2=tmp;
      b=i;
    }
  }
  set<pair<int,int>> ans;
  for(int i=0;i<3;i++){
    ans.insert({x[i],y[i]});
  }
  if(d1<d2){
    cout << d1 << endl;
    for(int i=0;i<3;i++){

      for(int j=min(x[i],ax);j<=max(x[i],ax);j++){
        ans.insert({j,y[i]});
      }
      for(int j=min(y[i],ay);j<=max(y[i],ay);j++){
        ans.insert({ax,j});
      }
    }
  }else{
    cout << d2 << endl;
    for(int i=0;i<3;i++){
      for(int j=min(x[i],x[b]);j<=max(x[i],x[b]);j++){
        ans.insert({j,y[i]});
      }
      for(int j=min(y[i],y[b]);j<=max(y[i],y[b]);j++){
        ans.insert({x[b],j});
      }
    }
  }
  for(auto p:ans){
    cout << p.first SP p.second << endl;
  }
  return 0;
}