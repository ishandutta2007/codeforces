#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> x(n),y(m);
  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  for(int i=0;i<m;i++){
    cin >> y[i];
  }
  bool first=true;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(x[i]==y[j]){
        if(first){
          cout << x[i];
          first=false;
        }else{
          cout << " " << x[i];
        }
      }
    }
  }
  return 0;
}