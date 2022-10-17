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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    a[i]=abs(a[i]);
  }
  sort(all(a));
  LL ans=0;
  rep(i,n){
    int idx = upper_bound(all(a),2*a[i])-a.begin()-1;
    ans+=idx-i;
  }
  cout << ans << endl;
  return 0;
}