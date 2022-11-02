#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int> 
#define VPI vector<PII> 
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())
#define int LL
const int M=512*1024;

struct node
{
  int best, left, right;
  int l, r;
  //0-equal, 1-left less 2-right less
};

int T[M], n, m, R[M];
int D[2*M];
node DH[2*M];

int get(int a, int b)
{
  if(a==b)
    return 0;
  if(a<b)
    return 1;
  return 2;
}

void add(int p, int k, int val)
{
  p+=M;
  k+=M;
  D[p]+=val;
  if(k!=p)
    D[k]+=val;
  while(p/2!=k/2)
  {
    if(p%2==0)
      D[p+1]+=val;
    if(k%2==1)
      D[k-1]+=val;
    p/=2;
    k/=2;
  }
}

int val(int ind)
{
  ind+=M;
  int res=D[ind];
  while(ind>1)
  {
    ind/=2;
    res+=D[ind];
  }
  return res;
}

void addh(int i, int val)
{
  i+=M;
  if(val==0)
  {
    DH[i].best=0;
    DH[i].left=0;
    DH[i].right=0;
  }
  else
  {
    DH[i].best=1;
    DH[i].left=1;
    DH[i].right=1;
  }
  while(i>1)
  {
    i/=2;
    DH[i].best=max(DH[2*i].best, DH[2*i+1].best);
    DH[i].left=DH[2*i].left;
    DH[i].right=DH[2*i+1].right;
    if(R[DH[2*i].r]==1 || R[DH[2*i+1].l]==2)
    {
      DH[i].best=max(DH[i].best, DH[2*i].right+DH[2*i+1].left);
      if(DH[i].left==(DH[i].r-DH[i].l+1)/2)
        DH[i].left+=DH[2*i+1].left;
      if(DH[i].right==(DH[i].r-DH[i].l+1)/2)
        DH[i].right+=DH[2*i].right;
    }
  }
}

main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%lld", &n);
  REP(i, M)
  {
    DH[i+M].l=i;
    DH[i+M].r=i;
  }
  FORD(i, M-1, 1)
  {
     DH[i].l=DH[2*i].l;
    DH[i].r=DH[2*i+1].r;
  }
  REP(i, n)
  {
    int a;
    scanf("%lld", &a);
    T[i]=a;
    if(i>0)
    {
      R[i-1]=get(T[i-1], T[i]);
      addh(i-1, R[i-1]);
    }
    add(i, i, a);
  }
  scanf("%lld", &m);
  REP(i, m)
  {
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    a--;
    b--;
    add(a, b, c);
    if(a>0)
    {
      R[a-1]=get(val(a-1), val(a));
      addh(a-1, R[a-1]);
    }
    if(b<n-1)
    {
      R[b]=get(val(b), val(b+1));
      addh(b, R[b]);
    }
    printf("%lld\n", DH[1].best+1);
  }
  return 0;
}