#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;

int main(){
  cin >> s;
  int n = s.size(); 
  vector<int>z(n);
  for(int i = 1, l = 0, r = 0; i < n; i++){
    if(i <= r){
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]){z[i]++;}
    if(i + z[i] - 1 > r){l = i; r = i + z[i] - 1;}
  }
  int ans = 0, zmax = 0;
  for(int i = 1; i < n; i++){
    if(z[i] == n - i){
      if(zmax >= n - i){
	ans = i; break;
      }
    }
    zmax = max(zmax, z[i]);
  }
  if(ans == 0){cout << "Just a legend";}
  else{
    cout << s.substr(ans, n - ans);
  }
  return 0;
}