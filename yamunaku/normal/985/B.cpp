#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  int count,num;
  vector<bool> flag(n,false);
  for(int i=0;i<m;i++){
    count=0;
    for(int j=0;j<n;j++){
      if(s[j][i]=='1'){
        num=j;
        count++;
      }
    }
    if(count==1){
      flag[num]=true;
    }
  }
  for(int i=0;i<n;i++){
    if(!flag[i]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}