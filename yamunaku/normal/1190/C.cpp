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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> l0(n+2,0),l1(n+2,0),r0(n+2,0),r1(n+2,0);
  rep(i,n){
    l0[i+1]=l0[i]+(s[i]=='0'?1:0);
    l1[i+1]=l1[i]+(s[i]=='1'?1:0);
  }
  per(i,n){
    r0[i+1]=r0[i+2]+(s[i]=='0'?1:0);
    r1[i+1]=r1[i+2]+(s[i]=='1'?1:0);
  }
  bool ok=false;
  repp(i,1,n-k+2){
    if(l0[i-1]==i-1&&r0[i+k]==n-(i+k)+1){
      cout << "tokitsukaze" << endl;
      return 0;
    }else if(l1[i-1]==i-1&&r1[i+k]==n-(i+k)+1){
      cout << "tokitsukaze" << endl;
      return 0;
    }else if(l0[i-1]==i-1&&r1[i+k]==n-(i+k)+1){
      if(i-1>k||n-(i+k)+1>k) ok=true;
    }else if(l1[i-1]==i-1&&r0[i+k]==n-(i+k)+1){
      if(i-1>k||n-(i+k)+1>k) ok=true;
    }else{
      if(i==1||i==n-k+1){
        if(n>2*k) ok=true;
      }else{
        ok=true;
      }
    }
  }
  if(ok){
    cout << "once again" << endl;
  }else{
    cout << "quailty" << endl;
  }
  return 0;
}