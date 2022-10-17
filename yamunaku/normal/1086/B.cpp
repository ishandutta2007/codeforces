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
  int n;
  cin >> n;
  LD s;
  cin >> s;
  vector<int> count(n,0);
  int u,v;
  for(int i=0;i<n-1;i++){
    cin >> u >> v;
    count[u-1]++;
    count[v-1]++;
  }
  int dd=0;
  for(int i=0;i<n;i++){
    if(count[i]==1) dd++;
  }
  if(dd==2){
    cout << fixed << setprecision(10) << s << endl;
  }else{
    cout << fixed << setprecision(10) << s/dd*2 << endl;
  }
  return 0;
}