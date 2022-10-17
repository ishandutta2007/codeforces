#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k,l;
  cin >> n >> k >> l;
  vector<int> a(n*k);
  for(int i=0;i<n*k;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int pos=distance(a.begin(),upper_bound(a.begin(),a.end(),a[0]+l));
  if(pos<n){
    cout << 0 << endl;
  }else{
    LL ans=0;
    ans+=(LL)a[0];
    for(int i=1;i<n;i++){
      ans+=(LL)a[min(i*k,pos+i-n)];
    }
    cout << ans << endl;
  }
  return 0;
}