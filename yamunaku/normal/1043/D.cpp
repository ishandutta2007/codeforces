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
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(m,vector<int>(n)),nex(m,vector<int>(n,-1));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&a[i][j]);
      a[i][j]--;
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n-1;j++){
      nex[i][a[i][j]]=a[i][j+1];
    }
  }
  vector<bool> mita(n,false);
  LL ans=0,count,ne;
  bool okflag;
  for(int i=0;i<n;i++){
    if(!mita[a[0][i]]){
      mita[a[0][i]]=true;
      count=1;
      ne=a[0][i];
      while(1){
        okflag=true;
        for(int j=1;j<m;j++){
          if(nex[0][ne]!=nex[j][ne]){
            okflag=false;
            break;
          }
        }
        if(okflag){
          if(nex[0][ne]==-1) break;
          count++;
          ne=nex[0][ne];
          mita[ne]=true;
        }else{
          break;
        }
      }
      ans+=count*(count+1)/2;
    }
  }
  cout << ans << endl;
  return 0;
}