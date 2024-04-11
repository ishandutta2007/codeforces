#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int count=1;
  int ans=n;
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      count++;
    }else{
      if(a[i]>a[i-1]&&a[i]<=a[i-1]+k) ans-=count;
      count=1;
    }
  }
  cout << ans << endl;
  return 0;
}