#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  string a,b;
  cin >> n >> a >> b;
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      ans++;
      if(i<n-1){
        if(a[i]!=a[i+1]&&b[i]!=b[i+1]){
          a[i+1]=b[i+1]='2';
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}