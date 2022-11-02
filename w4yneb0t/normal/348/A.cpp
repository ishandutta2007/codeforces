#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;
in a[200000];
int main(){
  in n;
  cin>>n;
  in v=0;
  for(in i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  v+=a[n-1];
  in gl=a[n-1];
  for(in i=0;i<n;i++){
    a[i]-=a[n-1];
    gl+=a[i];
    a[i]=0;
  }
  if(gl<=0){
    cout<<v<<endl;
    return 0;
  }
  cout<<v+(gl+n-2)/(n-1)<<endl;
  return 0;
}