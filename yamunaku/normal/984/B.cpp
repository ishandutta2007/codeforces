#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> field(n);
  int x[8] = {-1,-1,-1,0,0,1,1,1};
  int y[8] = {-1,0,1,-1,1,-1,0,1};
  for(int i=0;i<n;i++){
    cin >> field[i];
  }
  char count;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      count=0;
      if(field[i][j]!='*'){
        for(int k=0;k<8;k++){
          if(0<=j+x[k]&&j+x[k]<m&&0<=i+y[k]&&i+y[k]<n){
            if(field[i+y[k]][j+x[k]]=='*') count++;
          }
        }
        if(field[i][j]=='.'){
          if(count!=0){
            cout << "NO" << endl;
            return 0;
          }
        }else{
          if(field[i][j]-'0'!=count){
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}