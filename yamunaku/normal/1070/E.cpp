#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int q;
  cin >> q;
  LL n,m,t,rui,co,kyu,d;
  int l,r,mid;
  int ans1,ans2;
  for(int aaaa=0;aaaa<q;aaaa++){
    cin >> n >> m >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    l=0,r=200001;
    while(r-l>1){
      mid=(r+l)/2;
      rui=co=kyu=0;
      // cout << "------"<<mid << endl;
      for(int i=0;i<n;i++){
        if(a[i]<=mid){
          if(co%m==0){
            rui+=kyu;
            kyu=0;
          }
          // cout << rui << endl;
          rui+=a[i];
          kyu+=a[i];
          co++;
        }
      }
      if(t>=rui){
        l=mid;
      }else{
        r=mid;
      }
    }
    // cout << l << endl;
    d=l;
    rui=co=kyu=0;
    for(int i=0;i<n;i++){
      if(a[i]<=d){
        if(co%m==0){
          rui+=kyu;
          kyu=0;
        }
        rui+=a[i];
        kyu+=a[i];
        co++;
        // cout << rui << endl;
      }
    }
    ans1=co;
    d=l+1;
    rui=co=kyu=0;
    for(int i=0;i<n;i++){
      if(a[i]<=d){
        if(co%m==0){
          rui+=kyu;
          kyu=0;
        }
        // cout << rui << endl;
        if(rui>=t){
          ans2=co;
          break;
        }
        rui+=a[i];
        kyu+=a[i];
        if(rui>t){
          ans2=co;
          break;
        }
        co++;
      }
    }
    ans2=co;
    if(l==0){
      cout << ans2 SP min(l+1,t) << endl;
      continue;
    }
    if(ans1>=ans2){
      cout << ans1 SP min(l,t) << endl;
    }else{
      cout << ans2 SP min(l+1,t) << endl;
    }
  }
  return 0;
}