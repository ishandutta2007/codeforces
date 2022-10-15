#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int x){
  if(x<2)return 0;
  for(int i=2;i*i<=x;i++){
    if(x%i==0)return 0;
  }
  return 1;
}
int main(){
  cin>>n;
  if(check(n))puts("1");
  else if(n%2==0)puts("2");
  else if(check(n-2))puts("2");
  else puts("3");
  return 0;
}