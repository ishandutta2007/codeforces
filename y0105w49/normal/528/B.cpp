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

int n;
int x,w,lbound;
int xi[MAXN],wi[MAXN];
set<ii> s;

int mabs(int x) {
  if (x<0) return -x;
  return x;
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  REP(i,n) {
    cin >> x >> w;
    s.insert(mp(x+w,i));
    xi[i]=x;
    wi[i]=w;
  }
  xi[n]=-INF/2;
  wi[n]=0;
  int cnt = 0;
  int prev = n;
  foreach(j,s) {
    if (mabs(xi[j->second]-xi[prev])>=wi[j->second]+wi[prev]) {
      cnt++;
      prev = j->second;
    }
  }

  cout << cnt << endl;



}