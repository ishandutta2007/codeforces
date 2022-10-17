#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct kukan{
  LL l;
  LL r;
  bool operator<(const struct kukan & right) const{
    return l < right.l;
  }
};

int main(){
  LL n,h;
  cin >> n >> h;
  vector<struct kukan> x(n);
  for(int i=0;i<n;i++) cin >> x[i].l >> x[i].r;
  sort(x.begin(),x.end());
  vector<LL> ruiseki(n,0);
  for(int i=1;i<n;i++){
    ruiseki[i]=x[i].l-x[i-1].r+ruiseki[i-1];
  }
  int en;
  LL ans=h;
  for(int i=0;i<n;i++){
    en=distance(ruiseki.begin(),lower_bound(ruiseki.begin(),ruiseki.end(),ruiseki[i]+h)-1);
    ans=max(ans,x[en].r-x[i].l+h+ruiseki[i]-ruiseki[en]);
  }
  cout << ans << endl;
  return 0;
}