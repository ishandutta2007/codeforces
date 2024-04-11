#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  vector<int> u(n);
  vector<int> c(10,0);
  for(int i=0;i<n;i++){
    cin >> u[i],u[i]--;
    c[u[i]]++;
  }
  for(int i=n-1;i>=0;i--){
    vector<int> v(10);
    for(int j=0;j<10;j++) v[j]=c[j];
    sort(all(v),greater<int>());
    int x;
    if(v[1]==0) x = v[0];
    else x = v[1];
    bool usd=false;
    for(int j=0;j<10;j++){
      if(v[j]==0) continue;
      if(v[j]!=x){
        if(v[j]==1||v[j]==x+1){
          if(usd) goto next;
          usd=true;
        }else{
          goto next;
        }
      }
    }
    if(usd||(usd==false&&x==1)||v[1]==0){
      cout << i+1 << endl;
      return 0;
    }
    next:;
    c[u[i]]--;
  }
  return 0;
}