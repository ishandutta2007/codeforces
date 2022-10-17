#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct knight{
  LL p;
  LL c;
  bool operator<(const knight& right) const{
    return p<right.p;
  }
};

int main(){
  int n,k;
  cin >> n >> k;
  vector<LL> P(n);
  vector<struct knight> inikn(n);
  vector<struct knight> kn(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&(kn[i].p));
    P[i]=kn[i].p;
  }
  for(int i=0;i<n;i++){
    scanf("%lld",&(kn[i].c));
    inikn[i]=kn[i];
  }
  if(k>0){
    sort(P.begin(),P.end());
    sort(kn.begin(),kn.end());
    vector<vector<LL>> co(n,vector<LL>(k,0));
    co[0][0]=kn[0].c;
    bool flag;
    for(int i=1;i<n;i++){
      flag=false;
      for(int j=0;j<k;j++){
        if(kn[i].c>co[i-1][j]){
          for(int l=k-1;l>j;l--){
            co[i][l]=co[i-1][l-1];
          }
          co[i][j]=kn[i].c;
          for(int l=0;l<j;l++){
            co[i][l]=co[i-1][l];
          }
          flag=true;
          break;
        }
      }
      if(!flag){
        for(int j=0;j<k;j++){
          co[i][j]=co[i-1][j];
        }
      }
    }
    LL ans;
    int can;
    for(int i=0;i<n;i++){
      ans=0;
      can=distance(P.begin(),lower_bound(P.begin(),P.end(),inikn[i].p))-1;
      if(can>=0){
        for(int j=0;j<k;j++){
          ans+=co[can][j];
        }
      }
      ans+=inikn[i].c;
      if(i<n-1) printf("%lld ",ans);
      else printf("%lld",ans);
    }
  }else{
    for(int i=0;i<n;i++){
      if(i<n-1) printf("%lld ",inikn[i].c);
      else printf("%lld",inikn[i].c);
    }
  }
  return 0;
}