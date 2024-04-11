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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  int ans=0;
  int now=0;
  rep(i,n){
    if(a[i]>=now){
      ans=(ans+a[i]-now)%2;
      now++;
    }
  }
  int count=0;
  rep(i,n-2){
    if(a[i]==0&&a[i+1]==0){
      cout << "cslnb" << endl;
      return 0;
    }
    if(a[i]==a[i+1]){
      count++;
    }
    if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
      cout << "cslnb" << endl;
      return 0;
    }
    if(a[i]==a[i+1]-1&&a[i+1]==a[i+2]){
      cout << "cslnb" << endl;
      return 0;
    }
  }
  if(count>1){
    cout << "cslnb" << endl;
    return 0;
  }
  if(ans%2){
    cout << "sjfnb" << endl;
  }else{
    cout << "cslnb" << endl;
  }
  return 0;
}