#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> num(200001,0);
  int a;
  for(int i=0;i<n;i++){
    cin >> a;
    num[a+100000]++;
  }
  int ans=0;
  for(int i=0;i<200001;i++){
    if(num[i]){
      if(i!=100000) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}