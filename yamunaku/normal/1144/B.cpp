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
  int x;
  vector<int> a,b;
  int total=0;
  for(int i=0;i<n;i++){
    cin >> x;
    if(x%2){
      a.push_back(x);
    }else{
      b.push_back(x);
    }
    total+=x;
  }
  sort(all(a),greater<int>()),sort(all(b),greater<int>());
  int ans=0;
  int k=min(a.size(),b.size());
  for(int i=0;i<k;i++){
    ans+=a[i]+b[i];
  }
  if(a.size()>k) ans+=a[k];
  if(b.size()>k) ans+=b[k];
  cout << total-ans << endl;
  return 0;
}