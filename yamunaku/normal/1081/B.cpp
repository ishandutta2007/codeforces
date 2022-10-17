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
  vector<int> a(n);
  vector<int> count(n,0);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    count[a[i]]++;
  }
  for(int i=0;i<n;i++){
    if(count[i]%(n-i)){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  vector<pair<int,int>> b(n,{-1,0});
  int now=1;
  for(int i=0;i<n;i++){
    if(b[a[i]].second==0){
      b[a[i]]={now,n-a[i]};
      now++;
    }
    printf("%d ",b[a[i]].first);
    b[a[i]].second--;
  }
  cout << endl;
  return 0;
}