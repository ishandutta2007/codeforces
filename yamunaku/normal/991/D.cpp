#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  string up,down;
  cin >> up >> down;
  int n=up.length();
  vector<int> kosuu(n,0);
  for(int i=0;i<n;i++){
    if(up[i]=='0') kosuu[i]++;
    if(down[i]=='0') kosuu[i]++;
  }
  int ans=0;
  for(int i=1;i<n;i++){
    if(kosuu[i-1]==2){
      if(kosuu[i]>0){
        kosuu[i]--;
        ans++;
      }
    }else if(kosuu[i-1]==1){
      if(kosuu[i]==2){
        kosuu[i]-=2;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}