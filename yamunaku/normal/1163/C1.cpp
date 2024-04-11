#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL gcd(LL x,LL y){
  while(x%y){
    LL tmp = x%y;
    x = y;
    y = tmp;
  }
  return y;
}

int main(){
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }
  set<pair<pair<LL,LL>,pair<LL,LL>>> st;
  map<pair<LL,LL>,LL> mp;
  LL count=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      LL dx = x[i]-x[j];
      LL dy = y[i]-y[j];
      pair<LL,LL> d,b;
      // cout << dx SP dy << endl;
      if(dx == 0){
        d = {1, 0};
        b = {x[i], 0};
        if(st.find({d, b})==st.end()){
          st.insert({d, b});
          mp[d]++;
          count++;
        }
      }else if(dy==0){
        d = {0, 1};
        b = {y[i], 0};
        if(st.find({d, b})==st.end()){
          st.insert({d, b});
          mp[d]++;
          count++;
        }
      }else{
        LL g = gcd(dx,dy);
        d = {dy/g,dx/g};
        LL yy = y[i]*dx-x[i]*dy;
        LL xx = dx;
        LL gg = gcd(yy,xx);
        if(yy==0) b = {0,1};
        else b = {yy/g, xx/g};
        if(st.find({d,b})==st.end()){
          st.insert({d,b});
          mp[d]++;
          count++;
        }
      }
    }
  }

  LL ans=0;
  for(auto x:mp){
    ans += (count-x.second)*x.second;
  }
  cout << ans/2 << endl;
  return 0;
}