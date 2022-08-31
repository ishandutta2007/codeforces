#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int,int>
#define VI vector<int>
#define FI first
#define SE second
#define st FI
#define nd SE
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define LD long double

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h) { cerr << sdbg << "=" << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg != ',')cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {cout<<#C<<"="; for(auto&cc:C)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0)cout
#endif

#define MAX 100010
int SQR = sqrt(100000);


int n,m;
int dep[MAX];
int vis[MAX];
vector<PII> slo[MAX];
VI to_use;
int cnt;
int pot_ind[MAX];
VI paths[MAX];
void Ass(int v) {
  cnt++;
  paths[cnt-1] = to_use;
  assert(SZ(to_use) <= 4);
  to_use.clear();
  pot_ind[v] = cnt-1;
}
void Dfs(int v, int e_ind) {
  if (e_ind != -1) {
    to_use.PB(e_ind);
  }
  //to_use.PB(v);
  if (dep[v] % 2 == 0) {
    Ass(v);
  }
  vis[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (vis[nei]) { continue; }
    dep[nei] = dep[v] + 1;
    Dfs(nei, e.nd);
  }
  if (dep[v] % 2 == 1) {
    Ass(v);
  }
  if (e_ind != -1) {
    to_use.PB(e_ind);
  }
}

struct z{
  int x,y,nr;
};
vector<z> zap;
LL res[MAX];
int kt[MAX];
int kol[MAX];
int il[MAX];
int kubel[MAX];
bool czkr[MAX];
bool qzap(z a,z b){
  int aa = a.x/SQR;
  int bb = b.x/SQR;
  if(aa != bb){
    return aa < bb;
  }
  return (a.y < b.y) ^ (aa & 1);
}

const int N = 1e5 + 5;
VI vs[N];
LL cres;
int cnt_boy[N];
int cnt_girl[N];
bool is_boy[N];
int fav[N];
int is_in[N];
int adj[N];
LL get_res() {
//   RE (i, n) {
//     cerr<<is_in[i]<<" ";
//   }
//   cerr<<endl;
  return cres;
}
void AddGuy(int x) {
//   assert(is_in[x] == 0);
//   is_in[x] = 1;
  if (is_boy[x]) {
    cres += cnt_girl[fav[x]];
    cnt_boy[fav[x]]++;
  } else {
    cres += cnt_boy[fav[x]];
    cnt_girl[fav[x]]++;
  }
}
void DelGuy(int x) {
//   assert(is_in[x]);
//   is_in[x] = 0;
  if (is_boy[x]) {
    cres -= cnt_girl[fav[x]];
    cnt_boy[fav[x]]--;
  } else {
    cres -= cnt_boy[fav[x]];
    cnt_girl[fav[x]]--;
  }
}
void addScizka(int k){
  for(int x:paths[k]){
    czkr[x] = !czkr[x];
    if(czkr[x]){
      for (auto v : vs[x]) {
        adj[v]++;
        if (adj[v] == 1) {
          AddGuy(v);
        }
      }
    }else{
      for (auto v : vs[x]) {
        adj[v]--;
        if (adj[v] == 0) {
          DelGuy(v);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  
  cin >> n;
  RE (i, n) {
    cin>>is_boy[i];
  }
  unordered_map<int, int> all_fav;
  RE (i, n) {
    cin>>fav[i];
    all_fav[fav[i]] = 1;
  }
  int cntt = 0;
  for (auto& p : all_fav) {
    p.nd = cntt;
    cntt++;
  }
  RE (i, n) {
    fav[i] = all_fav[fav[i]];
    cerr<<fav[i]<<" ";
  }
  cerr<<endl;
  R(i,n-1){
    int a,b;
    cin>>a>>b;
    slo[a].PB({b,i});
    slo[b].PB({a,i});
    vs[i] = {a, b};
  }
  Dfs(1,-1);
  R(i,n+1){
    if(i){
      debug(i, pot_ind[i]);
      debugv(paths[i]);
    }
  }
  cin>>m;
  R(i,m){
    int a,b;
    cin >> a >> b;
    debug(a, b);
    a = pot_ind[a];
    b = pot_ind[b];
    if(a > b)swap(a,b);
    debug(a, b);
    zap.PB({a,b,i});
  }
  sort(ALL(zap),qzap);
  
  int x = 0,y = 0;
  R(i,m){
    while(x < zap[i].x){
      x++;
      addScizka(x);
    }
    while(x > zap[i].x){
      addScizka(x);
      x--;
    }
    while(y < zap[i].y){
      y++;
      addScizka(y);
    }
    while(y > zap[i].y){
      addScizka(y);
      y--;
    }
    debug(x,y);
    res[zap[i].nr] = get_res();
    
  }
  R(i,m){
    cout << res[i] << "\n";
  }
  
  return 0;
}