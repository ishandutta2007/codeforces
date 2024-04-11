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
  int t;
  cin >> t;
  for(int q=0;q<t;q++){
    int n;
    cin >> n;
    int ans=0,tmp;
    for(int i=0;i<8;i++){
      vector<int> v1,v2;
      for(int j=0;j<n;j++){
        if(j&(1<<i)){
          v1.push_back(j+1);
        }else{
          v2.push_back(j+1);
        }
      }
      if(v1.size()==0||v2.size()==0) continue;
      cout << v1.size() SP v2.size() << " ";
      for(int i=0;i<v1.size();i++){
        cout << v1[i] << " ";
      }
      for(int i=0;i<v2.size();i++){
        cout << v2[i] << " ";
      }
      cout << endl;
      cin >> tmp;
      ans=max(ans,tmp);
    }
    cout << -1 SP ans << endl;
  }
  return 0;
}