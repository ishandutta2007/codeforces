#include <iostream>
using namespace std;
int main() {
  cin.tie(0);ios_base::sync_with_stdio(0);
  long long int n, ans = 0;
  int m, tmp = 0;
  cin>>n>>m;
  int a[n];
  for (long long int i = 0; i < n; i++) cin>>a[i];
  int i = 0;
  while(i < n){
    // cout<<"run with i"<<i<<endl;
    // cout<<"now tmp = "<<tmp<<endl;
    tmp += a[i];
    if (tmp <= m){
      i++;
      // cout<<i<<" get in"<<endl;
    }
    else{
      // cout<<"car full"<<endl;
      tmp = 0;
      ans++;
    }
  }
  ans++;
  cout<<ans<<endl;
}