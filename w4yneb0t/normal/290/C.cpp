#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int tux,foo,bar,baz,quz;
  cin>>tux;
  foo=0;
  bar=0;
  baz=0;
  quz=1;
  int pur;
  for(;tux!=0;tux--){
    cin>>pur;
    foo=foo+pur;
    bar=bar+1;
    if(foo*quz>=bar*baz){
      baz=foo;
      quz=bar;
    }
  }
  cout<<(double)baz/quz<<endl;
  return 0;
}