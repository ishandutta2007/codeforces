#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in n,d;
bool rcb[600000];
in c[59];
int main(){
  cin>>n>>d;
  for(in i=0;i<n;i++)
    cin>>c[i];
  rcb[0]=1;
  in mr=0;
  for(in i=0;i<n;i++){
    for(in j=mr;j>=0;j--){
      rcb[j+c[i]]|=rcb[j];
    }
    mr+=c[i];
  }
  in cr=0;
  in ds=0;
  bool fd;
  do{
    fd=0;
    for(in i=cr+d;i>cr;i--){
      if(rcb[i]){
	fd=1;
	ds++;
	cr=i;
	break;
      }
    }
  }while(fd);
  cout<<cr<<" "<<ds<<endl;
  return 0;
}