#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n<6)cout<<-1<<endl;
  else{
    cout<<"1 2\n1 3\n1 4\n";
    for(int i=5;i<=n;i++)cout<<2<<" "<<i<<endl;
  }
  for(int i=2;i<=n;i++)cout<<1<<" "<<i<<endl;
}