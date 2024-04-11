#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;

int main(){
  in t;
  cin>>t;
  string yes="YES";
  string no="NO";
  char bd[8][8];
  in kx[2];
  in ky[2];
  in kc;
  for(in z=0;z<t;z++){
    kc=0;
    for(in i=0;i<8;i++){
      for(in j=0;j<8;j++){
        cin>>bd[i][j];
        if(bd[i][j]=='K'){
          kx[kc]=i;
          ky[kc++]=j;
        }
      }
    }
    in dy=ky[1]-ky[0];
    in dx=kx[1]-kx[0];
    if(dy%4 || dx%4){
      cout<<no<<endl;
      continue;
    }
    bool gc=0;
    for(in i=-8;i<=8;i+=2){
      in x=kx[0]+i;
      if(x<0 || x>=8)
        continue;
      for(in j=-8;j<=8;j+=2){
        in y=ky[0]+j;
        if(y<0 || y>=8)
          continue;
        if((i+j)%4)
          continue;
        if(bd[x][y]=='.' || bd[x][y]=='K')
          gc=1;
      }
    }
    if(gc)
      cout<<yes<<endl;
    else
      cout<<no<<endl;
  }
  return 0;
}