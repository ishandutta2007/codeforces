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
  int n,ax,ay,bx,by,cx,cy;
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  if((bx-ax)/abs(bx-ax)==(cx-ax)/abs(cx-ax)&&(by-ay)/abs(by-ay)==(cy-ay)/abs(cy-ay)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}