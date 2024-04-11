#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> c(n),a(m);
  for(int i=0;i<n;i++){
    cin >> c[i];
  }
  for(int i=0;i<m;i++){
    cin >> a[i];
  }
  int j=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if(j<m){
      if(c[i]<=a[j]){
        ans++;
        j++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}