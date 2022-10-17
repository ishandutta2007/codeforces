#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),(-a))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int s=0,l=0;
  int ans=0;
  while(l<n){
    for(;a[s]>=a[l]&&l<n;l++);
    if(l!=n) ans++;
    s++;
    l++;
  }
  cout << ans << endl;
  return 0;
}