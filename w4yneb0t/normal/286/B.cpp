#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int mp[3000009];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    mp[i]=i+1;
  }
  int mng=0;
  int tpl,tpn;
  for(int k=2;k<n;k++){
    mng--;
    tpl=mp[-1-mng];
    tpn=tpl;
    int j;
    for(j=-1-mng;mp[j+k]!=0;j+=k){
      tpl=mp[j+k];
      mp[j+k]=tpn;
      tpn=tpl;
    }
    mp[n-1-mng]=tpn;
  }
  mng--;
  mp[-1-mng+n]=mp[-1-mng];
  for(int i=n-1;i<2*n-1;i++){
    cout<<mp[i]<<" ";
  }
  cout<<"\n";
  return 0;
}