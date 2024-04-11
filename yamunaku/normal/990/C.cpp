#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> kosuu(2,vector<int>(300001,0));
  string s;
  int left,right,count=0;
  bool lefter,righter;
  for(int i=0;i<n;i++){
    cin >> s;
    lefter=false,righter=false;
    left=right=0;
    for(int j=0;j<s.length();j++){
      if(s[j]=='('){
        left++;
      }else{
        right++;
      }
      if(left-right<0){
        righter=true;
      }
    }
    left=right=0;
    for(int j=s.length()-1;j>=0;j--){
      if(s[j]=='('){
        left++;
      }else{
        right++;
      }
      if(right-left<0){
        lefter=true;
      }
    }
    if(lefter&&(!righter)){
      kosuu[0][left-right]++;
    }else if((!lefter)&&righter){
      kosuu[1][right-left]++;
    }else if((!lefter)&&(!righter)){
      count++;
    }
  }
  LL ans=(LL)count*(LL)count;
  for(int i=0;i<300001;i++){
    ans+=(LL)kosuu[0][i]*(LL)kosuu[1][i];
  }
  cout << ans << endl;
  return 0;
}