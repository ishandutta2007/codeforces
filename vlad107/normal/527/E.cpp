//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;


const int MAXN = 210000;

vector<int> g[MAXN];
int loopscnt[MAXN];
vector<int> used;
int degin[MAXN];
int degout[MAXN];

void fix(int v, int u){
  if (degout[v] % 2 == 1){
    swap(u, v);
  } 
  printf("%d %d\n", u + 1, v + 1);
  degin[v]++;
  degout[u]++;
}

void dfs(int v){
  int up = -1;
  used[v] = 1;
  for (auto u : g[v]){
    if (used[u] == 0){
      dfs(u);
      continue;
    }
    if (used[u] == 1){
      if (up == -1){
        up = u;
        continue;
      }
      fix(v, u);
    }
  }
  if (up != -1){
    fix(v, up);
  }
  assert(degin[v] % 2 == 0);
  assert(degout[v] % 2 == 0);
  used[v] = 2;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m;
  scanf("%d%d",&n,&m);
  for (int i = 0; i < m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    if (a == b){
      loopscnt[a]++;
    } else {
      g[a].pb(b);
      g[b].pb(a);
    }
  }

  int last = -1;
  for (int i = 0; i < n; i++){
    if (g[i].size() % 2 == 1){
      if (last == -1) last = i;
      else {
        g[last].pb(i);
        g[i].pb(last);
        m++;
        last = -1;
      }
    }
  }
  assert(last == -1);
  if (m % 2 == 1){
    loopscnt[0]++;
    m++;
  }
  printf("%d\n", m); 
  for (int i = 0; i < n; i++)
    for (int j = 0; j < loopscnt[i]; j++){
      printf("%d %d\n", i + 1, i + 1);
      degin[i]++;
      degout[i]++;
    }
  used.resize(n);
  dfs(0);    
  return 0;
}