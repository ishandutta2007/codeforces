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
  vector<int> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  sort(all(s));
  int ans=0;
  vector<int> b;
  for(int i=20;i>0;i--){
    b = vector<int>();
    vector<pair<int,int>> t;
    t.reserve(n);
    for(int j=0;j<n;j++){
      if(s[j]>=(1<<i)) break;
      t.push_back({s[j],s[j]});
    }
    int m = t.size();
    bool ok=true;
    int x;
    for(int j=i-1;j>=0;j--){
      bool ng=true;
      for(int k=0;k<m;k++){
        if(t[k].first&(1<<j)){
          b.push_back(t[k].second);
          x=t[k].first;
          ng=false;
          break;
        }
      }
      if(ng){
        ok=false;
        break;
      }
      for(int k=0;k<m;k++){
        if(t[k].first&(1<<j)){
          t[k].first^=x;
        }
      }
    }
    if(ok){
      ans = i;
      break;
    }
  }
  if(ans==0){
    cout << 0 << endl << 0 << endl;
    return 0;
  }
  cout << ans << endl;
  for(int i=0;i<(1<<ans);i++){
    int k=0;
    int bit=i^(i>>1);
    for(int j=0;j<ans;j++){
      if(bit&(1<<j)) k^=b[j];
    }
    cout << k << " ";
  }
  cout << endl;
  return 0;
}