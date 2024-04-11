#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  int k=1;
  for(;k*k<=n;k++);
  k--;
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    ans[i]=i+1;
  }
  for(int i=0;i<=n/k;i++){
    sort(ans.begin()+k*i,ans.begin()+min(k*(i+1),n),greater<int>());
  }
  for(int i=0;i<n-1;i++){
    cout << ans[i] << " " <<flush;
  }
  cout << ans[n-1] << endl;
  return 0;
}