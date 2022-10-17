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
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  CFS;
  int n;
  cin >> n;
  n*=2;
  vector<int> a(n);
  LL sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  sort(all(a));
  LL s=0;
  rep(i,n/2){
    s+=a[i];
  }
  if(s*2==sum){
    cout << -1 << endl;
  }else{
    rep(i,n){
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}