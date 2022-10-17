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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(all(a));
  int count=0;
  vector<int> ans1,ans2;
  ans2.push_back(a[0]);
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      ans1.push_back(a[i]);
      count++;
      if(count>1){
        cout << "NO" << endl;
        return 0;
      }
    }else{
      ans2.push_back(a[i]);
      count=0;
    }
  }
  sort(all(ans2),greater<int>());
  cout << "YES" << endl;
  cout << ans1.size() << endl;
  for(int i=0;i<ans1.size();i++) cout << ans1[i] << " ";
  cout << endl;
  cout << ans2.size() << endl;
  for(int i=0;i<ans2.size();i++) cout << ans2[i] << " ";
  cout << endl;
  return 0;
}