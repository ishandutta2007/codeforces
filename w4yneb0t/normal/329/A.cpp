#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long in;

int main(){
  in n;
  char ar[109][109];
  cin>>n;
  for(in i=0;i<n;i++){
    cin>>ar[i];
  }
  bool rowk=true;
  bool colk=true;
  for(in i=0;i<n;i++){
    bool ck=false;
    bool rk=false;
    for(in j=0;j<n;j++){
      if(ar[i][j]=='.')
        rk=true;
      if(ar[j][i]=='.')
        ck=true;
    }
    rowk&=rk;
    colk&=ck;
  }
  if(!rowk && !colk){
    cout<<"-1"<<endl;
    return 0;
  }
  if(rowk)
    colk=false;
  for(in i=0;i<n;i++){
    bool op=false;
    for(in j=0;j<n;j++){
      if(!op && rowk && ar[i][j]=='.'){
        cout<<i+1<<" "<<j+1<<endl;
        op=true;
      }
      if(!op && colk && ar[j][i]=='.'){
        cout<<j+1<<" "<<i+1<<endl;
        op=true;
      }
    }
  }
  return 0;
}