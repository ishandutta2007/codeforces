#include <iostream>
using namespace std;
int n;
int main()
{
  cin>>n;
  int ans=1;
  for (int i=2;i<=n;i++) {
    ans+=(i-1)*2*6;
  }
  cout<<ans;
}