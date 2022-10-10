#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<sstream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<functional>
#include<utility>
#include<numeric>
#include<bitset>
#include<iterator>
#define INF (int)1e9
#define MOD 1000000007
#define tr(c, it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define debug(x) cout<<#x" = "<<(x)<<endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz size
#define ll long long
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MEM(a, b) memset(a, (b), sizeof(a))
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?"\n":" ")
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?"\n":" ")
#define PRE(i, m, n, in) for(int (i)=(m);(i)<(n);i+=in)
#define RFOR(i, n) for(int i=n ; i>=0 ; i--)
#define RPRE(i, j, k, in) for(int i=j ; i>=k ; i-=in)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define ERS(A, P) A.erase(A.begin() + P)
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define toint(a) atoi(a.c_str())
using namespace std;
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
typedef vector <int> VI;
typedef vector <ll> VL;
typedef vector<string> VS;
typedef vector <VS> VSS;
typedef vector <II> VII;
typedef vector <LL> VLL;
typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VII> VVII;
typedef vector <VLL> VVLL;
typedef map<int,int> MPII;
typedef map<ll,ll> MPLL;
typedef map<string, int>MPSI;
typedef map<string, ll>MPSL;
typedef map<int, string>MPIS;
typedef map<ll, string> MPLS;
typedef map<string, string> MPSS;
typedef set<int> SETI;
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  // freopen("input.txt", "r", stdin);
  vector <int> a(6, 1);
  vector <int> rps(4);
  cout << "? " << 1 << " " << 2 << "\n";
  fflush(stdout);
  cin >> rps[0];

  cout << "? " << 2 << " " << 3 << "\n";
  fflush(stdout);

  cin >> rps[1];
  cout << "? " << 4 << " " << 5 << "\n";
  fflush(stdout);

  cin >> rps[2];
  cout << "? " << 5 << " " << 6 << "\n";
  fflush(stdout);
  cin >> rps[3];
  if(rps[0] % 23 == 0 || rps[1] % 23 == 0) {
    if(rps[0] % 23 == 0 && rps[1] % 23 == 0) {
      a[1] = 23; a[0] = rps[0]/a[1]; a[2] = rps[1]/a[1];
    }
    else if(rps[0] % 23 == 0) {
      a[0] = 23; a[1] = rps[0]/23; a[2] = rps[1]/a[1];
    }
    else if(rps[1] % 23 == 0) {
      a[2] = 23; a[1] = rps[1]/23; a[0] = rps[0]/a[1];
    }
    int mul = (4*8*15*16*23*42)/(a[0]*a[1]*a[2]);
    a[3] = mul/rps[3]; a[4] = rps[2]/a[3]; a[5] = mul/rps[2];
  }
  else if(rps[2] % 23 == 0 || rps[3] % 23 == 0) {
    if(rps[2] % 23 == 0 && rps[3] % 23 == 0) {
      a[4] = 23; a[3] = rps[2]/a[4]; a[5] = rps[3]/a[4];
    }
    else if(rps[2] % 23 == 0) {
      a[3] = 23; a[4] = rps[2]/23; a[5] = rps[3]/a[4];
    }
    else if(rps[3] % 23 == 0) {
      a[5] = 23; a[4] = rps[3]/23; a[3] = rps[2]/a[4];
    }
    int mul = (4*8*15*16*23*42)/(a[3]*a[4]*a[5]);
    a[0] = mul/rps[1]; a[1] = rps[0]/a[0]; a[2] = mul/rps[0];
  }
  cout << "! " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << "\n";
  fflush(stdout);
  return 0;
}