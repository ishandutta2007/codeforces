#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,s;
  cin >> n >> s;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  LL ans=0;
  if(a[n/2]>s){
    for(int i=0;i<=n/2;i++) ans+=max(a[i]-s,0);
  }else if(a[n/2]<s){
    for(int i=n/2;i<n;i++) ans+=max(s-a[i],0);
  }
  cout << ans << endl;
  return 0;
}