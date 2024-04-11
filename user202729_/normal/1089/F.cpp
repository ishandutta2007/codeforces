/*input
6
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
// const int N =;

int gcd(int a , int b){
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}

int n;

bool isPrimePower(int x){
  int lim = sqrt(x);
  int divi = -1;
  loop(i,2,lim){
    if (x%i==0){
      divi = i;
      break;
    }
  }  
  if (divi==-1) return true;
  while(x%divi==0){x/=divi;};
  if (x==1) return true;
  return false;
}

pair<int,int> getUV(int x){
    int lim = sqrt(x);
    loop(i,2,lim){
      if (x%i==0 && gcd(i,x/i)==1){
        return {i,x/i};
      }
    }
    assert(false);
}

int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

pair<int,int> findPQ(int u, int v){
  int p,q;
  assert(extgcd(u,v,p,q)==1);
  return {p,q}; 
}

int getLambda(int u, int q){
  // (n-1)*q/u
  int up = (n-1)*q;
  int down = u;
  if (up%down==0) return up/down;
  else{
    if (up<0) return up/down-1;
    else return up/down;
  }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; 
    if (isPrimePower(n)){
      cout << "NO" << endl;
      return 0;
    }
    auto [u,v] = getUV(n);
    auto [p,q] = findPQ(u,v);
    auto lambda = getLambda(u,q);    
    
    cout << "YES" << endl;
    cout << 2 << endl;
    cout << (n-1)*q-lambda*u << sp << u << endl;
    cout << (n-1)*p+lambda*v << sp << v << endl;
}