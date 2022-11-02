#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  int p[100009];
  int i;
  for(i=1;i<n/2;i+=2){
    p[i]=n-i;
    p[n-i]=n-i+1;
    p[n-i+1]=i+1;
    p[i+1]=i;
  }
  int r=n-i+1;
  if(r==i)
    p[i]=i;
  if(r==i+1 || r==i+2){
    cout<<-1<<endl;
    return 0;
  }
  for(int j=1;j<=n;j++){
    cout<<p[j]<<" ";
  }
  cout<<endl;
  return 0;
}