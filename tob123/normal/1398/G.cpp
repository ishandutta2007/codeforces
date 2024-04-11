#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const double PI = acos(-1);

//for extra speed use follwoing custom complex type
struct cpx {
  double a=0,b=0;
  cpx(){}
  cpx(double a):a(a){}
  cpx(double a, double b):a(a),b(b){}
  double modsq() {
    return a * a + b * b;
  }
  cpx bar() {
    return cpx(a, -b);
  }
  cpx operator /=(int n) {
    a /= n, b /= n;
    return *this;
  }
};
cpx operator +(cpx a, cpx b) {
  return cpx(a.a + b.a, a.b + b.b);
}
cpx operator -(cpx a, cpx b) {
  return cpx(a.a - b.a, a.b - b.b);
}
cpx operator *(cpx a, cpx b) {
  return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}
cpx operator /(cpx a, cpx b) {
  cpx r = a * b.bar();
  return cpx(r.a / b.modsq(), r.b / b.modsq());
}
using cd = cpx;
//otherwise use
//using cd = complex<double>;

void fft(vector<cd> & a, bool inv) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (j ^= bit; !(j&bit); j ^= (bit>>=1));
    if (i < j)
      swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (inv ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i+j], v = a[i+j+len/2] * w;
        a[i+j] = u + v; a[i+j+len/2] = u - v;
        w = w*wlen;
      }
    }
  }
  if (inv)
    for (cd & x : a)
      x /= n;
}

void mul(vector<cd> & a, vector<cd> & b) {
  int n = 1;
  while ((1 << n) < max(a.size(), b.size())) n++;
  n++;
  a.resize(1 << n);
  b.resize(1 << n);
  fft(a, false), fft(b, false);
  for (int i = 0; i < (int) a.size(); i++)
    a[i] = a[i] * b[i];
  fft(a, true);
}

int N, X, Y, Q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> X >> Y;
  vector<cd> A(X+1), B(X+1);
  for(int i=0; i<N+1; i++){
    int z;
    cin >> z;
    A[z].a++;
    B[X-z].a++;
  }
  vector<vector<int>> D(1000005);
  for(int i=1; i<=1e6; i++){
    for(int j=i; j<=1e6; j+=i){
      D[j].push_back(i);
    }
  }
  mul(A, B);
  /*
  for(int i=0; i<sz(A); i++){
    auto x = A[i];
    cout << i << ": " << x.a << " " << x.b << endl;
  }
  */
  A[X].a = 0;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int l;
    cin >> l;
    l /= 2;
    int bigd = -1;
    for(int d : D[l]){
      if(d >= Y && d-Y <= X && A[d-Y+X].a > 1e-5){
        bigd = 2*d;
      }
    }
    cout << bigd << " ";
  }
  cout << endl;
}