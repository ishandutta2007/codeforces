#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000003
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL modpow(LL x,LL n){
  LL ans=1;
  while(n){
    if(n&1) ans=ans*x%MOD;
    n>>=1;
    x=x*x%MOD;
  }
  return ans;
}

LL inv(LL x){
  return modpow(x,MOD-2);
}

class Ren{
private:
  int n;
  vector<vector<LL>> a;
  vector<LL> b;
public:
  Ren(vector<vector<LL>> ar,vector<LL> br) : a(ar), b(br) { n=a.size(); }

  vector<LL> solve(){
    for(int i=0;i<n;i++){
      bool ok=true;
      for(int j=i;j<n;j++){
        if(a[j][i]!=0){
          swap(a[i],a[j]);
          swap(b[i],b[j]);
          ok=false;
          break;
        }
      }
      if(ok) continue;
      LL r=inv(a[i][i]);
      for(int j=i+1;j<n;j++){
        LL t=r*a[j][i];
        for(int k=i;k<n;k++){
          a[j][k]=(a[j][k]-t*a[i][k]%MOD+MOD)%MOD;
        }
        b[j]=(b[j]-t*b[i]%MOD+MOD)%MOD;
      }
    }
    vector<LL> ans(n);
    for(int i=n-1;i>=0;i--){
      ans[i]=b[i];
      for(int j=n-1;j>i;j--){
        ans[i]=(ans[i]-ans[j]*a[i][j]%MOD+MOD)%MOD;
      }
      ans[i]=ans[i]*inv(a[i][i])%MOD;
    }
    return ans;
  }
};

class Poly{
private:
  int n;
  vector<LL> c;
public:
  Poly(){}
  Poly(vector<LL> cr) : c(cr) { n=c.size(); }

  LL val(LL x){
    LL ans=0;
    for(int i=0;i<n;i++){
      ans=(ans+c[i]*modpow(x,i)%MOD)%MOD;
    }
    return ans;
  }

  void disp(){
    for(int i=0;i<n;i++){
      cout << c[i] << " ";
    }
    cout << endl;
  }
};

// unsigned long xor128() {
//   static unsigned long x=122346119, y=36143069, z=52148629, w=88675123;
//   unsigned long t=(x^(x<<11));
//   x=y; y=z; z=w;
//   return ( w=(w^(w>>19))^(t^(t>>8)) );
// }

// class Tester{
// private:
//   Poly f;
// public:
//   Tester(int n){
//     vector<LL> a(n+1);
//     for(int i=0;i<=n;i++) a[i]=xor128()%MOD;
//     f=Poly(a);
//   }

//   LL query(LL x){
//     return f.val(x);
//   }

//   bool judge(LL x){
//     f.disp();
//     if(x==-1){
//       for(int i=0;i<MOD;i++){
//         if(f.val(i)==0){
//           cout << "WA" << endl;
//           return false;
//         }
//       }
//       cout << "AC" << endl;
//       return true;
//     }else{
//       if(f.val(x)==0){
//         cout << "AC" << endl;
//         return true;
//       }else{
//         cout << "WA" << endl;
//         return false;
//       }
//     }
//   }
// };

int main(){
  int n=10;
  vector<vector<LL>> a(n+1,vector<LL>(n+1));
  vector<LL> b(n+1);
  for(int i=0;i<=n;i++){
    cout << "? " << i << endl;
    cin >> b[i];
    for(int j=0;j<=n;j++){
      a[i][j]=modpow(i,j);
    }
  }
  Ren r(a,b);
  Poly f(r.solve());
  // f.disp();
  for(int i=0;i<MOD;i++){
    if(f.val(i)==0){
      cout << "! " << i << endl;
      return 0;
    }
  }
  cout << "! -1" << endl;
  return 0;
  // int n=10;
  // for(int i=0;i<1000;i++){
  //   cout << "Test " SP i SP ":" << endl;
  //   Tester t(n);
  //   vector<vector<LL>> a(n+1,vector<LL>(n+1));
  //   vector<LL> b(n+1);
  //   for(int i=0;i<=n;i++){
  //     b[i]=t.query(i);
  //     for(int j=0;j<=n;j++){
  //       a[i][j]=modpow(i,j);
  //     }
  //   }
  //   Ren r(a,b);
  //   Poly f(r.solve());
  //   f.disp();
  //   for(int i=0;i<MOD;i++){
  //     if(f.val(i)==0){
  //       if(!t.judge(i)) return 0;
  //       goto next;
  //     }
  //   }
  //  if(!t.judge(-1)) return 0;
  //   next:;
  //   cout << endl;
  // }
  // return 0;
}