#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int,int> tl;

const int n = 2e5+10;
const int size = 256*2*1024;
const int offset = size/2 - 1;

struct BIT{
  vector<int> bit;
  int sz;
  BIT(){ }
  BIT(int n){
    sz = n+1;
    bit.resize(n+1);
  }

  void update(int x, int val){
    x++;
    while(x < sz){
      bit[x] += val;
      x += x & (-x);
    }
  }

  int query(int x){
    x++;
    int res = 0;
    while(x > 0){
      res += bit[x];
      x -= x & (-x);
    }
    return res;
  }
};

struct node{
  BIT bit;
  vector<int> coord;

  int ind(int x){
    int l = 0, r = coord.size()-1;
    while(l < r){
      int m = (l+r)/2;
      if(coord[m] < x){
        l = m+1;
      }
      else{
        r = m;
      }
    }
    return l;
  }

  void update(int x, int val){
    int i = ind(x);
    bit.update(i, val);
  }

  int query(int l, int r){
    int i1 = ind(l);
    i1--;
    int i2 = ind(r);
    if(coord[i2] > r)
      i2--;
    return bit.query(i2) - bit.query(i1);
  }
};

int N, M;
vector<int> A, B;
int rev[n];
node S[size];

void update(int x, int y, bool ins){
  x += offset;
  if(ins){
    S[x].update(y, 1);
  }
  else{
    S[x].update(y, -1);
  }
  while(x != 0){
    x = (x-1)/2;
    if(ins){
      S[x].update(y, 1);
    }
    else{
      S[x].update(y, -1);
    }
  }
}

int query(int l, int r, int b, int t, int curl=0, int curr=offset, int cur=0){
  if(l > curr || r < curl)
    return 0;
  if(l <= curl && r >= curr){
    return S[cur].query(b, t);
  }
  int m = (curl+curr)/2;
  return query(l, r, b, t, curl, m, 2*cur+1) + query(l, r, b, t, m+1, curr, 2*cur+2);
}

void pushCoord(int x, int y){
  x += offset;
  S[x].coord.push_back(y);
  while(x != 0){
    x = (x-1)/2;
    S[x].coord.push_back(y);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  A.resize(N);
  B.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i]--;
    rev[A[i]] = i;
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
    B[i]--;
    pushCoord(rev[B[i]], i);
  }

  vector<tl> Q(M);
  vector<int> cpA = A;
  vector<int> cpB = B;
  for(int i=0; i<M; i++){
    int t;
    cin >> t;
    if(t == 1){
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      la--; ra--; lb--; rb--;
      Q[i] = make_tuple(la, ra, lb, rb);
      //cout << query(la, ra, lb, rb) << endl;
    }
    else{
      int x, y;
      cin >> x >> y;
      x--; y--;
      Q[i] = make_tuple(x, y, -1, -1);

      int i1 = rev[cpB[x]];
      int i2 = rev[cpB[y]];
      pushCoord(i1, y);
      pushCoord(i2, x);
      swap(cpB[x], cpB[y]);
    }
  }
  for(int i=0; i<size; i++){
    S[i].coord.push_back(1e8); //INF
    sort(S[i].coord.begin(), S[i].coord.end());
    S[i].coord.erase(unique(S[i].coord.begin(), S[i].coord.end()), S[i].coord.end());
    S[i].bit = BIT(S[i].coord.size());
  }

  for(int i=0; i<N; i++){
    update(rev[B[i]], i, true);
  }
  for(int i=0; i<M; i++){
    int la, ra, lb, rb;
    tie(la, ra, lb, rb) = Q[i];
    int x = la;
    int y = ra;
    int t = (lb == -1) ? 2 : 1;
    if(t == 1){
      cout << query(la, ra, lb, rb) << endl;
    }
    else{
      int i1 = rev[B[x]];
      int i2 = rev[B[y]];
      update(i1, x, false);
      update(i2, y, false);
      update(i1, y, true);
      update(i2, x, true);
      swap(B[x], B[y]);
    }
  }

  return 0;
}