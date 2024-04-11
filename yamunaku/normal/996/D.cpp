#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> pe(2*n);
  vector<bool> appeared(n,false);
  vector<int> junban(n);
  vector<int> one(n),two(n);
  int now=0;
  for(int i=0;i<2*n;i++){
    cin >> pe[i];
    pe[i]--;
    if(!appeared[pe[i]]){
      appeared[pe[i]]=true;
      junban[pe[i]]=now;
      one[now]=i;
      now++;
    }else{
      two[junban[pe[i]]]=i;
    }
  }
  for(int i=0;i<2*n;i++){
    pe[i]=junban[pe[i]];
  }
  // for(int i=0;i<2*n;i++){
  //   cout << pe[i] << " ";
  // }
  // cout << endl;
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=one[i];j<two[i];j++){
      if(pe[j]>i) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}