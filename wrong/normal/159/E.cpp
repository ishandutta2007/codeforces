#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

struct cube {
  int id, size;
  cube(int i, int s)
    : id(i), size(s) { }
};
bool operator < (const cube& a, const cube& b)
{
  return a.size != b.size ? a.size > b.size : a.id < b.id;
}

struct cubes {
  int cube_cnt;
  vector<cube> cs;
  vector<ll> h_sum;
  ll height;
  void calc_sum() {
    cube_cnt = cs.size();
    h_sum.resize(cs.size());
    h_sum[0] = cs[0].size;
    for(int i=1; i<(int)cs.size(); ++i)
      h_sum[i] = h_sum[i-1] + cs[i].size;
    height = h_sum.back();
  }
};
bool operator < (const cubes& a, const cubes& b)
{
  return a.cs.size() < b.cs.size();
}

ll construct(const cubes& a, const cubes& b)
{
  if(a.cube_cnt == b.cube_cnt)
    return a.height + b.height;
  if(a.cube_cnt < b.cube_cnt)
    return a.height + b.h_sum[a.cube_cnt];
  if(a.cube_cnt > b.cube_cnt)
    return a.h_sum[b.cube_cnt] + b.height;
}

int main()
{
  int n;
  map<int, int> col_id;
  vector<cubes> C;

  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    int c, s;
    scanf("%d%d", &c, &s);
    if(col_id.count(c) == 0) {
      int new_id = col_id.size();
      col_id[c] = new_id;
      C.push_back(cubes());
    }
    C[col_id[c]].cs.push_back(cube(i+1, s));
  }

  int m = col_id.size();
  for(int i=0; i<m; ++i) {
    sort(C[i].cs.begin(), C[i].cs.end());
    C[i].calc_sum();
  }
  sort(C.begin(), C.end());

  ll sol = -1;
  int best1, best2;
  vector<int> bests;
  for(int i=0, j; i<m; i=j) {
    for(j=i; j<m && C[i].cube_cnt==C[j].cube_cnt; ++j) ;
    if(j-i >= 2) {
      int max1 = i, max2 = i+1;
      if(C[i].height < C[i+1].height)
	swap(max1, max2);
      for(int k=i+2; k<j; ++k) {
	if(C[max1].height < C[k].height) {
	  max2 = max1;
	  max1 = k;
	} else if(C[max2].height < C[k].height) {
	  max2= k;
	}
      }
      ll tmp = construct(C[max1], C[max2]);
      if(sol < tmp) {
	sol = tmp;
	best1 = max1;
	best2 = max2;
      }
      bests.push_back(max1);
    } else {
      bests.push_back(i);
    }
  }

  int p = bests.size();
  for(int i=0; i<m; ++i) {
    int k;
    for(k=0; k<p && C[bests[k]].cube_cnt<C[i].cube_cnt; ++k) ;
    for(int j=0; j<k; ++j) {
      ll tmp = construct(C[bests[j]], C[i]);
      if(sol < tmp) {
	sol = tmp;
	best1 = bests[j];
	best2 = i;
      }
    }
  }

  vector<int> tower;
  if(C[best1].cube_cnt == C[best2].cube_cnt) {
    for(int i=0; i<C[best1].cube_cnt; ++i) {
      tower.push_back(C[best1].cs[i].id);
      tower.push_back(C[best2].cs[i].id);
    }
  } else {
    if(C[best1].cube_cnt > C[best2].cube_cnt)
      swap(best1, best2);
    tower.push_back(C[best2].cs[0].id);
    for(int i=0; i<C[best1].cube_cnt; ++i) {
      tower.push_back(C[best1].cs[i].id);
      tower.push_back(C[best2].cs[i+1].id);
    }
  }

  printf("%I64d\n%d\n", sol, tower.size());
  for(int i=0; i<(int)tower.size(); ++i)
    printf("%d%c", tower[i], i==(int)tower.size()-1 ? '\n' : ' ');
  return 0;
}