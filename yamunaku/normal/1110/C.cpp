#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int q;
  cin >> q;
  int a;
  for(int t=0;t<q;t++){
    cin >> a;
    for(int i=2;i<=25;i++){
      if(a==(1<<i)-1){
        for(int i=2;i<=sqrt(a);i++){
          if(a%i==0){
            cout << a/i << endl;
            goto next;
          }
        }
        cout << 1 << endl;
        goto next;
      }
    }
    for(int i=25;i>=0;i--){
      if(a&(1<<i)){
        cout << ((1<<(i+1))-1) << endl;
        goto next;
      }
    }
    next:;
  }
  return 0;
}