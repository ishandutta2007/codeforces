#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<LL> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  sort(all(s));
  vector<LL> dis(n-1);
  for(int i=0;i<n-1;i++){
    dis[i]=s[i+1]-s[i];
  }
  sort(all(dis));
  vector<LL> rui(n,0);
  for(int i=1;i<n;i++){
    rui[i]=rui[i-1]+dis[i-1];
  }
  int q;
  cin >> q;
  LL l,r;
  vector<LL> ans(q);
  for(int t=0;t<q;t++){
    cin >> l >> r;
    LL d=r-l+1;
    int idx=lower_bound(all(dis),d)-dis.begin();
    ans[t]=rui[idx]+d*(n-idx);
  }
  for(int i=0;i<q;i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}