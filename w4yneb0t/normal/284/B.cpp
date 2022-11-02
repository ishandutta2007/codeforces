#include<iostream>
using namespace std;

int main(){
  int n;
  char c[200009];
  cin>>n;
  cin>>c;
  int a,f,in;
  a=0;
  f=0;
  in=0;
  for(int i=0;i<n;i++){
    if(c[i]=='A')
      a++;
    if(c[i]=='F')
      f++;
    if(c[i]=='I')
      in++;
  }
  if(in>=2)
    cout<<0<<endl;
  if(in==1)
    cout<<1<<endl;
  if(in==0)
    cout<<a<<endl;
  return 0;
}