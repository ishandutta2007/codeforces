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
  int k;
  cin >> k;
  vector<char> vw={'a','i','u','e','o'};
  repp(i,5,k){
    repp(j,5,k){
      if(i*j>k) break;
      if(i*j==k){
        rep(x,i){
          rep(y,j){
            cout << vw[(x+y)%5];
          }
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}