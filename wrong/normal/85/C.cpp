#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

struct tree {
  int key, par;
  int left, right;
  int lo, hi, leaf;
  int ql, qr;
  tree() {
    left = right = -1;
  }
} T[100050];

struct query {
  int id, k, val;
  double sol;
};

struct leaf {
  int key, lo, hi;
  vector<query> Q;
};
vector<leaf> L;
bool operator < (const query& a, const query& b)
{
  return a.id < b.id;
}

void search_leaf(int p, int ql=1, int qr=1000000001)
{
  if(T[p].left < 0) {
    T[p].lo = T[p].hi = p;
    leaf x;
    x.key = T[p].key;
    x.lo = ql;
    x.hi = qr;
    T[p].leaf = L.size();
    L.push_back(x);
    return;
  }
  search_leaf(T[p].left, ql, T[p].key);
  search_leaf(T[p].right, T[p].key+1, qr);
  T[p].lo = T[T[p].left].lo;
  T[p].hi = T[T[p].right].hi;
}

void dfs(int p, int cnt, ll sum)
{
  if(T[p].left < 0) {
    leaf& x = L[T[p].leaf];
    for(int i=0; i<(int)x.Q.size(); ++i)
      x.Q[i].sol = sum / (double)cnt;
    return;
  }
  dfs(T[p].left, cnt+1, sum+T[T[T[p].right].lo].key);
  dfs(T[p].right, cnt+1, sum+T[T[T[p].left].hi].key);
}

int main()
{
  int n, root;
  scanf("%d", &n);
  for(int i=1; i<=n; ++i) {
    int p, k;
    scanf("%d%d", &p, &k);
    T[i].key = k;
    T[i].par = p;
  }
  for(int i=1; i<=n; ++i) {
    if(T[i].par == -1) { root=i; continue; }
    int p = T[i].par;
    if(T[p].key < T[i].key) T[p].right = i;
    else T[p].left = i;
  }
  search_leaf(root);
  int m;
  scanf("%d", &m);
  for(int i=0; i<m; ++i) {
    int k;
    scanf("%d", &k);
    query q;
    q.id = i;
    q.k = k;
    int lo=0, hi=(int)L.size();
    while(hi-lo > 1) {
      int mid = (hi+lo)/2;
      if(L[mid].lo > k) hi = mid;
      else lo = mid;
    }
    q.val = L[lo].key;
    L[lo].Q.push_back(q);
  }
  dfs(root, 0, 0);
  vector<query> Q;
  for(int i=0; i<(int)L.size(); ++i)
    for(int j=0; j<(int)L[i].Q.size(); ++j)
      Q.push_back(L[i].Q[j]);
  sort(Q.begin(), Q.end());
  for(int i=0; i<(int)Q.size(); ++i)
    printf("%.10f\n", Q[i].sol);
  return 0;
}