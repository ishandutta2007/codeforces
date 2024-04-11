#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct a{
  int id;
  int t;
  bool operator<(const struct a & right) const{
    return t<right.t;
  }
};

int main(){
  int n,m,d;
  cin >> n >> m >> d;
  int ai;
  vector<int> ans(n,-1);
  set<struct a> ma;
  for(int i=0;i<n;i++){
    cin >> ai;
    ma.insert({i,ai});
  }
  set<struct a>::iterator now,pre;
  int i=1;
  for(;;i++){
    now=ma.begin();
    if(now==ma.end()) break;
    ans[now->id]=i;
    while(1){
      pre=now;
      now=ma.upper_bound({0,now->t+d});
      if(now==ma.end()) break;
      ans[now->id]=i;
      ma.erase(pre);
    }
    ma.erase(pre);
  }
  cout << i-1 << endl;
  for(int k=0;k<n-1;k++){
    cout << ans[k] << " ";
  }
  cout << ans[n-1] << endl;
  return 0;
}