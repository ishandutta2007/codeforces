#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin>>k;
  map<int,pair<int,int>> cnt;
  for(int q=0;q<k;q++){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=a[i];
    }
    for(int i=0;i<n;i++){
      int tt=sum-a[i];
      if(!cnt[tt].first){
        cnt[tt]={q+1,i+1};
      }else{
        if(cnt[tt].first!=q+1){
          cout<<"YES"<<endl<<cnt[tt].first<<" "<<cnt[tt].second<<endl<<q+1<<" "<<i+1;
          return 0;
        }
      }
    }
  }  
  cout<<"NO";
}