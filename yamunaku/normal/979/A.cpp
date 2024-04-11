#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int main(){
  long long n;
  cin >> n;
  n++;
  long long ans=0;
  if(n==1){
    cout << 0 << endl;
    return 0;
  }
  if(n%2){
    ans=n;
  }else{
    ans=n/2;
  }
  cout << ans << endl;
  return 0;
}