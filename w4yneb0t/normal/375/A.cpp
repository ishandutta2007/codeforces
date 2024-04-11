#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;

int a[1000009];
bool hv[4];
int main(){
  int p[4]={1,6,8,9};
  in l=0;
  char tp;
  in nzr=0;
  while(cin>>tp){
    bool fd=0;
    if(tp<'0' || tp>'9')
      break;
    for(in i=0;i<4;i++){
      if(!hv[i] && (tp-'0'==p[i])){
	hv[i]=1;
	fd=1;
	break;
      }
    }
    if(!fd){
      if(tp=='0')
	nzr++;
      else
	a[l++]=tp-'0';
    }
  }
  in ma=0;
  in mt=10000%7;
  for(in i=l-1;i>=0;i--){
    ma+=(a[i]*mt);
    mt=(mt*10)%7;
  }
  ma%=7;
  in cr;
  do{
    cr=(p[0]*1000+p[1]*100+p[2]*10+p[3]+ma)%7;
    if(cr==0){
      for(in i=0;i<l;i++)
	cout<<a[i];
      cout<<p[0]<<p[1]<<p[2]<<p[3];
      for(in i=0;i<nzr;i++)
	cout<<0;
      cout<<endl;
      break;
    }
  }while(next_permutation(p,p+4));
  return 0;
}