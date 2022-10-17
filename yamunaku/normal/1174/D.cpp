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
  int n,x;
  cin >> n >> x;
  if((1<<n)-1<x){
    cout << ((1<<n)-1) << endl;
    repp(i,1,(1<<n)){
      cout << (i^(i-1)) << " ";
    }
    cout << endl;
  }else{
    cout << ((1<<(n-1))-1) << endl;
    int pre = 0;
    vector<bool> usd(1<<n,false);
    usd[0]=usd[x]=true;
    repp(i,1,(1<<n)){
      if(!usd[i]){
        usd[i^x]=true;
        cout << (i^pre) << " ";
        pre=i;
      }
    }
    cout << endl;
  }
  return 0;
}