#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  if(n==1||n==2){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if(n%2){
    cout << 1 << " " << n << endl;
    cout << n-1 << " " << flush;
    for(int i=1;i<=n-2;i++){
      printf("%d ",i);
    }
    cout << n-1 << endl;
  }else{
    cout << (n+2)/4*2 << " " << flush;
    for(int i=1;i<=n/2;i+=2){
      printf("%d %d ",i,n-i+1);
    }
    cout << endl;
    cout << n/4*2 << " " << flush;
    for(int i=2;i<=n/2;i+=2){
      printf("%d %d ",i,n-i+1);
    }
    cout << endl;
  }
  return 0;
}