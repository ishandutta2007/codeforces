#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  if(n==1){
    cout << "YES" << endl << 0 << endl;
    return 0;
  }
  if((a>1&&b>1)){
    cout << "NO" << endl;
    return 0;
  }else{
    if(a==b){
      if(n==2||n==3){
        cout << "NO" << endl;
        return 0;
      }else{
        cout << "YES" << endl;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i==j){
              cout << 0;
            }else if((i==0&&j<n-1)||(j==0&&i<n-1)){
              cout << 1;
            }else if((i==n-1&&j==n-2)||(i==n-2&&j==n-1)){
              cout << 1;
            }else{
              cout << 0;
            }
          }
          cout << endl;
        }
      }
    }else{
      cout << "YES" << endl;
      if(a==1){
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i==j){
              cout << 0;
            }else if(i<b-1||j<b-1){
              cout << 1;
            }else{
              cout << 0;
            }
          }
          cout << endl;
        }
      }else{
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i==j){
              cout << 0;
            }else if(i<a-1||j<a-1){
              cout << 0;
            }else{
              cout << 1;
            }
          }
          cout << endl;
        }
      }
    }
  }
  return 0;
}