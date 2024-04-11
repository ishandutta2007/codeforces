#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  string s,t;
  cin >> s >> t;
  if(s.length()<t.length()){
    for(int i=0;i<q;i++) cout << 0 << endl;
    return 0;
  }
  vector<int> kosuu(n+1,0);
  for(int i=0;i<=s.length()-t.length();i++){
    kosuu[i+1]++;
    for(int j=0;j<t.length();j++){
      if(s[i+j]!=t[j]){
        kosuu[i+1]--;
        break;
      }
    }
  }
  // cout<< kosuu[0] << " ";
  for(int i=1;i<=n;i++){
    kosuu[i]+=kosuu[i-1];
    // cout << kosuu[i] << " ";
  }
  // cout << endl;
  int l,r;
  for(int i=0;i<q;i++){
    cin >> l >> r;
    if(r<l+t.length()-1){
      cout << 0 << endl;
      continue;
    }
    r-=t.length()-1;
    // cout << kosuu[r] << "," << kosuu[l-1] << endl;
    cout << kosuu[r]-kosuu[l-1] << endl;
  }
  return 0;
}