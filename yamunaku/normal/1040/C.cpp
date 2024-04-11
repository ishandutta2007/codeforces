#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n,t;
  cin >> n >> t;
  vector<LL> a(n),x(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    cin >> x[i];
    if(x[i]<=i){
      cout << "No" << endl;
      return 0;
    }
    if(i>0){
      if(x[i-1]>x[i]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  for(int i=0;i<n-1;i++){
    if(x[i]<x[i+1]){
      if(x[i]!=i+1){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if(x[n-1]!=n){
    cout << "No" << endl;
    return 0;
  }
  for(int i=1;i<n-1;i++){
    if(x[i-1]==x[i]&&x[i]<x[i+1]){
      if(a[i+1]-a[i]==1){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  for(int i=0;i<n-1;i++){
    if(x[i]==x[i+1]){
      printf("%lld ",a[i+1]+t);
    }else{
      if(i>0){
        if(x[i-1]==x[i]){
          printf("%lld ",a[i]+t+1);
        }else{
          printf("%lld ",a[i]+t);
        }
      }else{
        printf("%lld ",a[i]+t);
      }
    }
  }
  if(x[n-2]==x[n-1]) cout << a[n-1]+t+1 << endl;
  else cout << a[n-1]+t << endl;
  return 0;
}