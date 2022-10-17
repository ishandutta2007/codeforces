#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  vector<LL> num(4,0);
  for(int i=0;i<n;i++){
    num[(a[i]-'0')*2+(b[i]-'0')]++;
  }
  // cout << num[0] << num[1] << num[2] << num[3] << endl;
  cout << num[0]*num[3]+num[1]*num[2]+num[0]*num[2] << endl;
  return 0;
}