#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long a[n];
  map<long long,long long> cnt;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n;i++)cnt[a[i]]++;
  int ans=1;
  vector<long long> res={a[0]};
  for(int i=0;i<n;i++){
    for(int j=0;j<31;j++){
      long long mudja=pow(2,j),sane=pow(2,j+1);
      if(cnt[a[i]-mudja]){
        if(ans==1){
          ans=2;
          res={a[i],a[i]-mudja};
        }
      }
      if(cnt[a[i]-mudja]&&cnt[a[i]-sane]){
        ans=3;
        res={a[i],a[i]-mudja,a[i]-sane};
      }
    }
  }
  cout<<ans<<endl;
  for(auto c:res)cout<<c<<" ";
  /*for(int i=0;i<n;i++){
    for(int j=0;j<30;j++){
      long long mudja=pow(2,j),sane=pow(2,j+1);
      int ccc=1;
      if(cnt[a[i]-mudja])ccc=2;
      if(cnt[a[i]-mudja]&&cnt[a[i]-sane])ccc=3;
      if(ccc==ans){
        if(ccc==1)cout<<a[i];
        if(ccc==2)cout<<a[i]<<" "<<a[i]-mudja;
        if(ccc==3)cout<<a[i]<<" "<<a[i]-mudja<<" "<<a[i]-sane;
        return 0; 
      }
    }
  }*/
}