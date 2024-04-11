#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n;
  int a[109];
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  cin>>m;
  int x,y;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    a[x+1]+=a[x]-y;
    a[x-1]+=y-1;
    a[x]=0;
  }
  for(int i=1;i<=n;i++){
    cout<<a[i]<<endl;
  }
  return 0;
}