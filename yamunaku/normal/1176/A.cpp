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
  LL q;
  cin >> q;
  LL n;
  rep(t,q){
    cin >> n;
    int x=0;
    while(n%5==0){
      n/=5;
      x+=3;
    }
    while(n%3==0){
      n/=3;
      x+=2;
    }
    while(n%2==0){
      n/=2;
      x++;
    }
    if(n==1){
      cout << x << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}