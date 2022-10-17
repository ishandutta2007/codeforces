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
  int n,t;
  cin >> n >> t;
  pair<int,int> ans={IINF,-1};
  int s,d;
  for(int i=0;i<n;i++){
    cin >> s >> d;
    int k=s;
    for(;k<t;k+=d);
    ans=min(ans,{k,i+1});
  }
  cout << ans.second << endl;
  return 0;
}