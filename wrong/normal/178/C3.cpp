#include<cstdio>
#include<vector>
#include<cassert>
#include<map>

using namespace std;

struct BIT {
  int N;
  vector<int> B;
  BIT(int n = 0) {
    N = n;
    B.resize(n+2, 0);
  }
  void add(int x, int v) {
    x++;
    while(x <= N) {
      B[x] += v;
      x += x & -x;
    }
  }
  int sum(int x) {
    int s = 0;
    x++;
    while(x > 0) {
      s += B[x];
      x -= x & -x;
    }
    return s;
  }
  int sum(int a, int b) {
    return sum(b)-sum(a-1);
  }
};

int main()
{
  int h, m, n;
  scanf("%d%d%d", &h, &m, &n);

  long long sol = 0;
  map<int, pair<int, int> > pos;

  vector<BIT> X;
  vector<bool> visited(h, false);
  vector<int> ai(h), bi(h);
  for(int i=0; i<h; ++i) {
    if(!visited[i]) {
      int cnt = 0;
      for(int j=i; !visited[j]; j=(j+m)%h) {
	visited[j] = true;
	ai[j] = X.size(); bi[j] = cnt;
	cnt++;
      }
      X.push_back(BIT(cnt));
    }
  }

  for(int i=0; i<n; ++i) {
    char op[8];
    scanf("%s", op);

    int id, hs;
    if(op[0] == '-') {
      scanf("%d", &id);
      X[pos[id].first].add(pos[id].second, -1);
    } else {
      scanf("%d%d", &id, &hs);

      int xi = ai[hs], ti = bi[hs];
      assert(X[xi].sum(0, X[xi].N-1) < X[xi].N);

      if(X[xi].sum(ti, X[xi].N-1) == X[xi].N-ti) {
	int lo = -1, hi = ti-1;
	sol += X[xi].N - ti;
	while(hi-lo > 1) {
	  int mid = (hi+lo) / 2;
	  if(X[xi].sum(0, mid) == mid+1) lo = mid;
	  else hi = mid;
	}
	sol += hi;
	X[xi].add(hi, 1);
	pos[id] = make_pair(xi, hi);
      } else {
	int lo = ti-1, hi = X[xi].N-1;
	while(hi-lo > 1) {
	  int mid = (hi+lo) / 2;
	  if(X[xi].sum(ti, mid) == mid-ti+1) lo = mid;
	  else hi = mid;
	}
	sol += hi - ti;
	X[xi].add(hi, 1);
	pos[id] = make_pair(xi, hi);
      }
    }
  }

  printf("%I64d\n", sol);
  return 0;
}