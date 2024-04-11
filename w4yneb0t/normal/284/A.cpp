#include<iostream>
using namespace std;

int main(){
  int p;
  cin>>p;
  int tot=0;
  for(int i=1;i<p;i++){
    int j=i;
    bool ok=true;
    for(int k=1;k<p-1;k++){
      if(j==1){
	ok=false;
	break;
      }
      j*=i;
      j%=p;
    }
    if(j!=1)
      ok=false;
    tot+=ok;
  }
  cout<<tot<<endl;
  return 0;
}