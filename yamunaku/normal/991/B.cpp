#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  int g;
  vector<int> ko(6,0);
  double total=0;
  for(int i=0;i<n;i++){
    cin >> g;
    ko[g]++;
    total+=g;
  }
  int ans=0;
  int now=2;
  while(total/n<4.5){
    if(ko[now]>0){
      ko[now]--;
      total+=5-now;
      ans++;
    }else{
      now++;
    }
  }
  cout << ans << endl;
  return 0;
}