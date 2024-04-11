#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(2*n+1);
  if(n%2==0)puts("NO");
  else{
    puts("YES");
    for(int i=1;i<=n;i++){
      if(i&1){
        a[i]=2*i-1;
        a[i+n]=2*i;
      }else{
        a[i+n]=2*i-1;
        a[i]=2*i;
      }
    }
    for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
  }
}