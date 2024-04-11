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
  int m,n;
  cin >> m >> n;
  vector<vector<bool>> flag(m,vector<bool>(n));
  int s,x;
  rep(i,m){
    cin >> s;
    rep(j,s){
      cin >> x;
      flag[i][x-1]=true;
    }
  }
  rep(i,m){
    repp(j,i+1,m){
      rep(k,n){
        if(flag[i][k]&&flag[j][k]) goto next;
      }
      cout << "impossible" << endl;
      return 0;
      next:;
    }
  }
  cout << "possible" << endl;
  return 0;
}