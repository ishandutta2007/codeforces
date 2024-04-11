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
  int q;
  cin >> q;
  rep(t,q){
    LL a,b,m;
    cin >> a >> b >> m;
    if(a==b){
      cout << 1 SP a << endl;
      continue;
    }
    for(LL i=1,xxx=1;1;i*=2,xxx++){
      if(b<i*(a+1)) break;
      if(i*(a+1)<=b&&b<=i*(a+m)){
        vector<LL> ans(xxx,1);
        LL p=b-i*(a+1);
        for(LL j=i/2,idx=0;j>=1;j/=2,idx++){
          LL aa=min(p/j,m-1);
          ans[idx]+=aa;
          p-=aa*j;
        }
        ans[xxx-1]+=p;
        vector<LL> x(xxx+1,0);
        cout << xxx+1 << " ";
        x[0]=a;
        rep(j,xxx){
          cout << x[j] << " ";
          rep(jj,j+1) x[j+1]+=x[jj];
          x[j+1]+=ans[j];
        }
        cout << x[xxx] << endl;
        goto next;
      }
    }
    cout << -1 << endl;
    next:;
  }
  return 0;
}