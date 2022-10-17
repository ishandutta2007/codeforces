#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> c(n);
  for(int i=0;i<n;i++) cin >> c[i];
  int ans=0;
  for(int i=0;i<n/2;i++){
    if(c[i]==c[n-i-1]){
      if(c[i]==2){
        ans+=2*min(a,b);
      }
    }else{
      if(c[i]==2){
        ans+=(c[n-i-1]?b:a);
      }else if(c[n-i-1]==2){
        ans+=(c[i]?b:a);
      }else{
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if(n%2&&c[n/2]==2){
    ans+=min(a,b);
  }
  cout << ans << endl;
  return 0;
}