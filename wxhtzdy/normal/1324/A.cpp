#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i]%2;}
    if(sum==0||sum==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}