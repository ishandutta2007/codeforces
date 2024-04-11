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
  int n,k;
  cin >> n >> k;
  vector<bool> use(n,true);
  vector<int> ty(n);
  int countx,county;
  int x=1,y=2;
  string res;
  while(1){
    for(int i=1;i<=n;i++){
      if(i!=x&&i!=y&&use[i]){
        cout << '?' SP x SP i SP y  << endl;
        cin >> res;
        if(res=="Yes") y=i;
      }
    }
    ty[x]=0,ty[y]=1;
    countx=county=1;
    for(int i=1;i<=n;i++){
      if(i!=x&&i!=y&&use[i]){
        cout << '?' SP x SP y SP i  << endl;
        cin >> res;
        if(res=="Yes"){
          ty[i]=1;
          county++;
        }else{
          ty[i]=0;
          countx++;
        }
      }
    }
    if(countx>county){
      if(countx==n-n/k){
        cout << '!' SP x << endl;
        return 0;
      }
      for(int i=1;i<=n;i++){
        if(ty[i]==1) use[i]=false;
      }
      for(int i=1;i<=n;i++){
        if(use[i]&&i!=x) y=i;
      }
    }else{
      if(county==n-n/k){
        cout << '!' SP y << endl;
        return 0;
      }
      for(int i=1;i<=n;i++){
        if(ty[i]==0) use[i]=false;
      }
      x=y;
      for(int i=1;i<=n;i++){
        if(use[i]&&i!=x) y=i;
      }
    }
  }
  return 0;
}