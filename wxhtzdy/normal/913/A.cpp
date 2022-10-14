#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  if(n<=30)cout<<m%(int)pow(2,n);
  else cout<<m;
}