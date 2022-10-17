#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  vector<int> count(26,0);
  for(int i=0;i<n;i++){
    count[s[i]-'A']++;
  }
  int ans=1000000;
  for(int i=0;i<k;i++) ans=min(ans,count[i]);
  cout << ans*k << endl;
  return 0;
}