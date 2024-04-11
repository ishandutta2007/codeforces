#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct lady {
  int B, I, R;
  lady() : B(-1), I(-1), R(-1) { }
};
bool operator < (const lady& a, const lady& b)
{
  if(a.B!=b.B) return a.B<b.B;
  if(a.I!=b.I) return a.I<b.I;
  if(a.R!=b.R) return a.R<b.R;
  return false;
}

lady L[500000];
vector<int> B, I, R;

struct seg {
  int l, r;
  int val;
};
seg S[3000000];
void init(int x, int l, int r)
{
  if(r-l <= 1) {
    S[x].l = l;
    S[x].r = r;
    S[x].val = -1;
    return;
  }
  int mid = (l+r) >> 1;
  S[x].l = l;
  S[x].r = r;
  S[x].val = -1;
  init(2*x, l, mid);
  init(2*x+1, mid, r);
  return;
}
void change(int x, int pos, int val)
{
  if(S[x].r - S[x].l <= 1) {
    S[x].val = max(S[x].val, val);
    return;
  }
  int mid = (S[x].l+S[x].r) >> 1;
  if(pos < mid) {
    change(2*x, pos, val);
    S[x].val = max(S[x].val, S[2*x].val);
  } else {
    change(2*x+1, pos, val);
    S[x].val = max(S[x].val, S[2*x+1].val);
  }
  return;
}
int query(int x, int l, int r)
{
  if(S[x].l == l && S[x].r == r) {
    return S[x].val;
  }
  int mid = (S[x].l+S[x].r) >> 1;
  if(r < mid) return query(2*x, l, r);
  if(l >= mid) return query(2*x+1, l, r);
  return max(query(2*x, l, mid), query(2*x+1, mid, r));
}

int main()
{
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d", &L[i].B);
  for(int i=0; i<N; ++i) scanf("%d", &L[i].I);
  for(int i=0; i<N; ++i) scanf("%d", &L[i].R);
  for(int i=0; i<N; ++i) {
    B.push_back(L[i].B);
    I.push_back(L[i].I);
    R.push_back(L[i].R);
  }
  sort(B.begin(), B.end());
  sort(I.begin(), I.end());
  sort(R.begin(), R.end());
  B.erase(unique(B.begin(), B.end()), B.end());
  I.erase(unique(I.begin(), I.end()), I.end());
  R.erase(unique(R.begin(), R.end()), R.end());
  for(int i=0; i<N; ++i) {
    L[i].B = lower_bound(B.begin(), B.end(), L[i].B) - B.begin();
    L[i].I = lower_bound(I.begin(), I.end(), L[i].I) - I.begin();
    L[i].R = lower_bound(R.begin(), R.end(), L[i].R) - R.begin();
  }
  init(1, 0, I.size());
  sort(L, L+N);
  int sol = 0;
  for(int i=N-1; i>=0; ) {
    int fst = i;
    while(L[i].B == L[fst].B) {
      if(L[i].I+1 < I.size()) {
	int maxr = query(1, L[i].I+1, I.size());
	if(L[i].R < maxr) sol++;
      }
      i--;
      if(i < 0) break;
    }
    for(int j=fst; j>i; --j) {
      change(1, L[j].I, L[j].R);
    }
  }
  printf("%d\n", sol);
  return 0;
}