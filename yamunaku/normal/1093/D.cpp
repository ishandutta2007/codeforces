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
#define MOD 998244353
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL ruijo[300000];

int main(){
  int q;
  cin >> q;
  ruijo[0]=1;
  for(int i=1;i<300000;i++){
    ruijo[i]=ruijo[i-1]*2%MOD;
  }
  for(int t=0;t<q;t++){
    int n,m;
    cin >> n >> m;
    vector<list<int>> e(n);
    int u,v;
    for(int i=0;i<m;i++){
      cin >> u >> v;
      e[u-1].push_back(v-1);
      e[v-1].push_back(u-1);
    }
    list<pair<int,int>> aaa;
    vector<int> c(n,-1);
    queue<int> bfs;
    int zero,one,now;
    bool okflag=true;
    for(int i=0;i<n;i++){
      if(c[i]==-1){
        c[i]=0;
        zero=1,one=0;
        bfs.push(i);
        while(!bfs.empty()){
          now=bfs.front();
          bfs.pop();
          for(auto j:e[now]){
            if(c[j]==-1){
              if(c[now]==0){
                c[j]=1;
                one++;
              }else{
                c[j]=0;
                zero++;
              }
              bfs.push(j);
            }else{
              if(c[now]==c[j]){
                cout << 0 << endl;
                okflag=false;
                break;
              }
            }
          }
          if(!okflag) break;
        }
        if(!okflag) break;
        aaa.push_back({zero,one});
      }
    }
    if(!okflag) continue;
    LL ans=1;
    for(auto p:aaa){
      // cout << p.first SP p.second << endl;
      ans=(ruijo[p.first]+ruijo[p.second])%MOD*ans%MOD;
    }
    cout << ans << endl;
  }
  return 0;
}