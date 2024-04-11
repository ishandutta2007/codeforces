#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  vector<int> x={4,8,15,16,23,42};
  map<int,int> mp;
  rep(i,6){
    repp(j,i+1,6){
      mp[x[i]*x[j]]=(1<<i)+(1<<j);
    }
  }
  int val;
  cout << "?" SP 1 SP 2 << endl;
  cin >> val;
  int a=mp[val];
  cout << "?" SP 2 SP 3 << endl;
  cin >> val;
  int b=mp[val];
  cout << "?" SP 4 SP 5 << endl;
  cin >> val;
  int c=mp[val];
  cout << "?" SP 5 SP 6 << endl;
  cin >> val;
  int d=mp[val];
  int ans[6];
  ans[1] = a&b;
  ans[0] = a^ans[1];
  ans[2] = b^ans[1];
  ans[4] = c&d;
  ans[3] = c^ans[4];
  ans[5] = d^ans[4];
  cout << "! ";
  rep(i,6){
    rep(j,6){
      if(ans[i]&(1<<j)){
        cout << x[j] << " ";
        break;
      }
    }
  }
  cout << endl;
  return 0;
}