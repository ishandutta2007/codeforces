#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define foreach(v,c) for(typeof((c).begin()) v = (c).begin(); v!=(c).end(); ++v)
#define all(c) (c).begin(), (c).end()
#define REP(i,n) for(int i=0; i<n; i++)
#define F(i,L,R) for(int i=L; i<R; i++)

#define printA(a,L,R) F(puf,L,R) cout << a[puf] << (puf==(R-1)?'\n':' ')
#define prinvV(a) printA(a,0,a.size())

#define dbg(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ld> vld;

#define PI 3.1415926535897932384626
#define INF 2001000009
#define EPS 1e-8
#define MAXN 262144
#define MOD 1000000007

struct pt {
  ld x;
  ld y;
  ld z;
};

ll w,h,n;
set<ll> vcuts,hcuts;
multiset<ll> vdeltas,hdeltas;

int main() { ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> w >> h >> n;
  vcuts.insert(0);
  vcuts.insert(w);
  hcuts.insert(0);
  hcuts.insert(h);
  vdeltas.insert(w);
  hdeltas.insert(h);
  char c;
  int cut;
  ll l,r;
  ll hsize,vsize;
  REP(zz,n) {
    cin >> c >> cut;
    //    cout << c << cut << endl;
    if (c=='H') {
      r = *(hcuts.lower_bound(cut));
      l = *(--(hcuts.lower_bound(cut)));
      //      dbg(*(hdeltas.find(r-l)));
      hdeltas.erase(hdeltas.find(r-l));
      hcuts.insert(cut);
      hdeltas.insert(cut-l);
      hdeltas.insert(r-cut);
    } else {
      r = *(vcuts.lower_bound(cut));
      l = *(--(vcuts.upper_bound(cut)));
      //      dbg(*(vdeltas.find(r-l)));
      vdeltas.erase(vdeltas.find(r-l));
      vcuts.insert(cut);
      vdeltas.insert(cut-l);
      vdeltas.insert(r-cut);
    }
    hsize=*(--hdeltas.end());
    vsize=*(--vdeltas.end());
    cout << (hsize*vsize) << endl;
    //    usleep(1000000);
  }
}