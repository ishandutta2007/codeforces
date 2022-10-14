#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  if(x==2&&y==4||x==4&&y==2){
    cout<<"=";
    return 0;
  }
  if(x==2&&y==3){
    cout<<"<";
    return 0;
  }
  if(x==3&&y==2){
    cout<<">";
    return 0;
  }
  if(x==y){
    cout<<"=";
    return 0;
  }
  if(x==1){
    cout<<"<";
    return 0;
  }
  if(y==1){
    cout<<">";
    return 0;
  }
  if(x>y){
    cout<<"<";
    return 0;
  }
  if(y>x){
    cout<<">";
    return 0;
  }
}