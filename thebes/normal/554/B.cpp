#include <bits/stdc++.h>
using namespace std;

map<string,int> cnt;
string s; int n, ans;

int main(){
  for(scanf("%d",&n);n;n--){
    cin >> s;
    cnt[s]++;
  }
  for(auto v : cnt)
    if(v.second>ans) ans=v.second;
  printf("%d\n",ans);
  return 0;
}