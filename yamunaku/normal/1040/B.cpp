#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k;
  cin >> n >> k;
  cout << (n+2*k)/(2*k+1) << endl;
  for(int i=k;i>=0;i--){
    if(i+((n+2*k)/(2*k+1)-1)*(2*k+1)<n){
      for(int j=i;j<n;j+=2*k+1){
        printf("%d",j+1);
        if(j+2*k+1<n) printf(" ");
        else printf("\n");
      }
      return 0;
    }
  }
  return 0;
}