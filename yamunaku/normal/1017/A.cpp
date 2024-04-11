#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  int a,b,c,d;
  int j;
  for(int i=0;i<n;i++){
    cin >> a >> b >> c >> d;
    A[i]=a+b+c+d;
    if(i==0) j=A[i];
  }
  sort(A.begin(),A.end());
  for(int i=0;i<n;i++){
    if(A[n-i-1]==j){
      cout << i+1 << endl;
      return 0;
    }
  }
  return 0;
}