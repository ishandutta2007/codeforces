#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <complex>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}


const int N = 1 << 21;
typedef complex<double> CD;
const double kEps = .0000001;
const double kPi = 2 * acos(0);

int pot2(int n)
{
    int bla=1;
    while(bla<=n)
    {
        bla*=2;
    }
    return bla;
}
CD t[N];

void fft(int n, int p, int s, int q, int znak, CD *A) // n-stopien, p-przesuniecie, s-skok, q-miejsce gdzie zapisujemy w pamieci 
{
    if(n==1)
    {
        t[q]=A[p];
        return;
    }
    CD en=exp( CD (0, 2*kPi*znak/n) );
    CD e=1;
    fft(n/2, p, 2*s, q, znak, A);
    fft(n/2, p+s, 2*s, q+n/2, znak, A);
    for(int r=q; r<q+n/2; r++)
    {
        
        CD z=t[r]+t[r+n/2]*e;
        t[r+n/2]=t[r]-t[r+n/2]*e;
        t[r]=z;
        e*=en;
    }
}
void licz(int n, CD *A, CD *B, CD *C) // do C wpisuje wielomian A*B, gdzie n>deg(C)
{
    n=pot2(n+1);
    fft(n, 0, 1, 0, 1, A);
    for(int i=0; i<n; i++)
    {
        A[i]=t[i];
    }
    fft(n, 0, 1, 0, 1, B);
    for(int i=0; i<n; i++)
    {
        B[i]=t[i];
    }
    for(int i=0; i<n; i++)
    {
        C[i]=A[i]*B[i];
    }
    fft(n, 0, 1, 0, -1, C);
    for(int i=0; i<n; i++)
    {
        C[i]=t[i];
        C[i]= CD ( round(real(C[i])/n), 0.0);
    } 
}

CD bags[N];
CD res[N];
vector<int> to_print;
CD to_fft1[N], to_fft2[N];;
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  debug(kPi);
  make2(int, n, m);
  FOR (i, 0, 2 * m) {
    bags[i] = 0;
    to_fft1[i] = 0;
    to_fft2[i] = 0;
    res[i] = 0;
  }
  RE (i, n) {
    make(int, a);
    //cout<<a<<endl;
    bags[a] = 1;
    to_fft1[a] = 1;
    to_fft2[a] = 1;
  }
  //debug(real(res[1]));;
  licz(2 * m, to_fft1, to_fft2, res);
  
  RE (i, m) {
    //debug(i);
    //debug(real(res[i]));
    int a = round(real(res[i])), b = round(real(bags[i]));
    //debug(a);
    if (a > 0 && b == 0) {
      cout<<"NO\n";
      return 0;
    } else if (a == 0 && b > 0) {
      to_print.PB(i);
    }
  }
  cout<<"YES\n"<<SZ(to_print)<<"\n";
  for (int i = 0; i < SZ(to_print); i++) {
    cout<<to_print[i]<<" ";
  }
  cout<<"\n";
  
  // nie zapomnij o ll
  return 0;
}