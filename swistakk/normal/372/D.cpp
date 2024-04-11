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
#endif
#ifndef LOCAL
#define debug(x)
#define debugv(x)
#endif
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

const int N = 201 * 1001;
const int M = 1 << 19;

vector<int> slo[M];
int drz[2*M+5];
int pre[M];
int inv[M];
bool vis[M];
int ind[M];
int dep[M];
int size[M];
int d;
int jump[N][22];
int akt;
inline int czyt(int a, int b)
{
    a+=M-1;
    b+=M-1;
    int minii = min(drz[a], drz[b]);
    while((a >> 1) != (b >> 1))
    {
        if((a & 1)==0)
        {
            mini(minii, drz[a+1]);
        }
        if(b & 1)
        {
            mini(minii, drz[b-1]);
        }
        a >>= 1;
        b >>= 1;
    }
    return minii;
}
void dfs(int v, int par)
{
    vis[v]=true;
    pre[v]=d;
    size[v] = 1;
    inv[d]=v;
    d++;
    drz[akt+M-1]=pre[v];
    ind[pre[v]]=akt;
    akt++;
    
    int log = 0;  
    jump[v][0] = par;
    int act_anc = par;
    while (log < 20) {
      log++;
      jump[v][log] = jump[act_anc][log - 1];
      act_anc = jump[v][log];
    }
    
    
    for(int i=0; i<slo[v].size(); i++)
    {
      int nei = slo[v][i];
        if(!vis[nei])
        {
            dep[nei] = dep[v] + 1;
            dfs(nei, v);
            size[v] += size[nei];
            drz[akt+M-1]=pre[v];
            ind[pre[v]]=akt;
            akt++;
        }
    }
    
  
    
    
}

inline int lca(int a, int b) // pobiera a i b, a zwraca ich lca (przy ukorzenieniu w jedynce (ale to mozna zmienic zapuszczajac skad inad dfsa) )
{
  if (1ll * a * b == 0) {
    return a + b;
  }
    a=pre[a];
    b=pre[b];
    return inv[czyt(min(ind[a], ind[b]), max(ind[a], ind[b]))];
}

inline int add_edge(int a, int b) {
  slo[a].PB(b);
  slo[b].PB(a);
}

int drzlca[2 * M + 5];

int lcaall(int a, int b) {
  int res = lca(a, b);
  a += M - 1;
  b += M - 1;
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      res = lca(res, drzlca[a + 1]);
    }
    if (b % 2 == 1) {
      res = lca(res, drzlca[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return res;
}

int drzpre[2 * M + 5];

void dodaj(int a, int val) {
  a += M - 1;
  while (a) {
    drzpre[a] += val;
    a /= 2;
  }
}

int sumuj(int a, int b) {
  a += M - 1;
  b += M - 1;
  int res = drzpre[a];
  if (b != a) {
    res += drzpre[b];
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      res += drzpre[a + 1];
    }
    if (b % 2 == 1) {
      res += drzpre[b - 1];
    }
    a /= 2;
    b /= 2;
  }
  return res;
}

int skiknij(int v, int wys) {
  /* int pot = 1;
  int log = 0;
  while (2 * pot <= wys) {
    pot *= 2;
    log++;
  }
  int act_v = v;
  for
  while (wys) {
    if (pot & wys) {
      act_v = jump[act_v][log] */
  int act_v = v;
  for (int i = 0; i < 20; i++) {
    if (wys & (1 << i)) {
      act_v = jump[act_v][i];
    }
  }
  return act_v;
}

int eheh(int v) {
  int kl = 0, kp = dep[v], aktc, faj = -1;
  while (kl <= kp) {
    aktc = (kl + kp) / 2;
    int newv = skiknij(v, aktc);
    if (sumuj(pre[newv], pre[newv] + size[newv] - 1) == 0) {
      faj = aktc;
      kl = aktc + 1;
    } else {
      kp = aktc - 1;
    }
  }
  return faj + 1;
}

int act_size;
int l, r;
void dod(int v) {
  int now = lcaall(l, v);
  int old = lcaall(l, v - 1);
  if (now != old) {
    act_size += dep[v] + dep[old] - 2 * dep[now];
  } else {
    act_size += eheh(v);
  }
  dodaj(pre[v], 1);
}

void remove(int v) {
  int old = lcaall(v, r);
  int now = lcaall(v + 1 , r);
  
  dodaj(pre[v], -1);
  if (now != old) {
    act_size -= dep[v] + dep[now] - 2 * dep[old];
  } else {
    act_size -= eheh(v);
  }
}

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  int n, k;
  cin>>n>>k;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    add_edge(a, b);
  }
  RE (i, n) {
    drzlca[M + i - 1] = i;
  }
  
  
  d=1;
  akt=1;
  dfs(1, 0);
  for(int i=M-1; i>=1; i--)
  {
      drz[i]=min(drz[i << 1], drz[(i << 1)+1]);
  }
  
  FORD (i, M - 1, 1) {
    drzlca[i] = lca(drzlca[2 * i], drzlca[2 * i + 1]);
  }
  
  
  debug(skiknij(8, 5))
  
  RE (i, n) {
    debug(i);
    debug(pre[i]);
    debug(size[i]);
  }
  
  
  
  
  
  
  act_size = 1;
  l = 1;
  r = 1;
  dodaj(pre[1], 1);
  int best = 1;
  for (r = 2; r <= n; r++) {
    dod(r);
    while (act_size > k) {
      remove(l);
      l++;
    }
    maxi(best, r - l + 1);
    debug(r);
    debug(l);
    debug(act_size);
  }
  cout<<best<<endl;
  
  // nie zapomnij o ll
  return 0;
}