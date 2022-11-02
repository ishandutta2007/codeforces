#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  int tw[109];
  int on[109];
  int nt=0;
  int no=0;
  int tp;
  for(int i=0;i<n;i++){
    cin>>tp;
    if(tp==1)
      cin>>on[no++];
    else
      cin>>tw[nt++];
  }
  sort(tw,tw+nt);
  sort(on,on+no);
  int bt=100000000;
  int twt=0;
  int ont=0;
  for(int i=0;i<=nt;i++){
    ont=0;
    for(int j=0;j<=no;j++){
      if(ont+twt<=2*(nt-i)+no-j && bt>2*(nt-i)+no-j)
	bt=2*(nt-i)+no-j;
      if(j<no)
	ont+=on[j];
    }
    if(i<nt)
      twt+=tw[i];
  }
  cout<<bt<<endl;
  return 0;
}