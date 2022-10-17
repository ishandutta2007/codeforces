#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  if(n==1){
    cout << a[0] << endl;
    return 0;
  }
  bool sei=false,hu=false,zero=false;
  for(int i=0;i<n;i++){
    if(a[i]>0) sei=true;
    else if(a[i]<0) hu=true;
    else zero=true;
  }
  LL total=0,mi=1000000001;
  for(int i=0;i<n;i++){
    total+=abs(a[i]);
    mi=min(mi,abs(a[i]));
  }
  if((sei&&hu)||zero){
    cout << total << endl;
  }else{
    cout << total-2*mi << endl;
  }
  return 0;
}