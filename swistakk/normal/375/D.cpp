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
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 1001 * 101;
int col[N];
vector<int> slo[N];
vector<int> ver[22];
vector<pair<int, int> > queries[N];
int res[N];
int size[N];
vector<int> col_num[22];
vector<int> at_least[22];

void dfs1(int v) {
  size[v] = 1;
  for (int i = 0; i < slo[v].size(); i++) {
    int nei = slo[v][i];
    if (size[nei] == 0) {
      dfs1(nei);
      size[v] += size[nei];
    }
    
  }
}

void add_v(int log, int col_v, bool root) {
  ver[log].PB(col_v);
  col_num[log][col_v]++;
  at_least[log][col_num[log][col_v]]++;
  if (!root) {
    at_least[log + 1][col_num[log + 1][col_v]]--;
    col_num[log + 1][col_v]--;
  }
}

void dfs2(int v, int log) {
  int max_size = 0;
  int gdz = 0;
  //cout<<v<<" "<<slo[v].size()<<endl;
  for (int i = 0; i < slo[v].size(); i++) {
    int nei = slo[v][i];
    if (size[nei] > size[v]) {
      continue;
    }
    if (size[nei] > max_size) {
      max_size = size[nei];
      gdz = i;
    }
  }
  if (size[v] > 1) {
    dfs2(slo[v][gdz], log); 
    for (int i = 0; i < slo[v].size(); i++) {
      int nei = slo[v][i];
      if (size[nei] < size[v] && i != gdz) {
        dfs2(nei, log + 1);
        for (int j = 0; j < ver[log + 1].size(); j++) {
          add_v(log, ver[log + 1][j], false);
        }
        ver[log + 1].clear();
      }
    }
  }
  add_v(log, col[v], true);
  for (int i = 0; i < queries[v].size(); i++) {
    //cout<<"odp na "<<queries[v][i].second<<" to "<<at_least[log][queries[v][i].first]<<endl;
    res[queries[v][i].second] = at_least[log][queries[v][i].first];
  }
}

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  
  int n, q;
  cin>>n>>q;
  for (int i = 1; i <= n; i++) {
    cin>>col[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  for (int i = 1; i <= q; i++) {
    int v, k;
    cin>>v>>k;
    queries[v].PB(MP(k, i));
  }
  
  for (int i = 0; i < 22; i++) {
    at_least[i].resize(N);
    col_num[i].resize(N);
  }
  
  dfs1(1);
  dfs2(1, 1);
  //cout<<"hehe"<<endl;
  for (int i = 1; i <= q; i++) {
    cout<<res[i]<<"\n";
  }
  //cout<<"lol"<<endl;
  // nie zapomnij o ll
  return 0;
}