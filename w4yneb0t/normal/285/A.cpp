#include<iostream>
#include<algorithm>
#define forn(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin>>n>>k;
  for(int i=k+1;i<=n;i++){
    cout<<i<<" ";
  }
  for(int i=k;i>=1;i--){
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}