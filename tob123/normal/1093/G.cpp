#include <bits/stdc++.h>
using namespace std;

struct p{
  int c[5] = {0, 0, 0, 0, 0};
};
struct node{
  bool qr = false;
  p best[32];
};

const int n = 2e5+10;
const int size = 1024*256*2;
const int offset = size/2 - 1;

int N, K;

p P[n];
node S[size];

inline int par(int x){
  return (x-1)/2;
}
inline int left(int x){
  return 2*x+1;
}
inline int right(int x){
  return 2*x+2;
}

node toNode(p cur){
  node res;
  for(int i=0; i<32; i++){
    res.best[i] = cur;
  }
  return res;
}

node comb(node a, node b){
  if(a.qr)
    return b;
  if(b.qr)
    return a;
  node res;
  for(int i=0; i<32; i++){
    int suma=0, sumb=0;
    for(int j=0; j<5; j++){
      if(i & (1<<j)){
        suma += a.best[i].c[j];
        sumb += b.best[i].c[j];
      }
      else{
        suma -= a.best[i].c[j];
        sumb -= b.best[i].c[j];
      }
    }
    if(suma > sumb){
      res.best[i] = a.best[i];
    }
    else{
      res.best[i] = b.best[i];
    }
  }
  return res;
}

void update(int x){
  S[x+offset] = toNode(P[x]);
  x += offset;
  while(x != 0){
    x = par(x);
    S[x] = comb(S[left(x)], S[right(x)]);
  }
}

void constructSeg(){
  for(int i=0; i<N; i++){
    S[offset+i] = toNode(P[i]);
  }
  for(int i=offset-1; i>=0; i--){
    S[i] = comb(S[left(i)], S[right(i)]);
  }
}

node query(int l, int r, int curl=0, int curr=offset, int cur=0){
  if(curl > r || curr < l){
    node res;
    res.qr = true;
    return res;
  }
  if(l <= curl && r >= curr){
    return S[cur];
  }
  int m = (curl+curr)/2;
  node n1 = query(l, r, curl, m, left(cur));
  node n2 = query(l, r, m+1, curr, right(cur));
  return comb(n1, n2);
}

int dist(p a, p b){
  int res = 0;
  for(int i=0; i<5; i++){
    res += abs(a.c[i]-b.c[i]);
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for(int i=0; i<N; i++){
    for(int j=0; j<K; j++){
      cin >> P[i].c[j];
    }
  }
  constructSeg();
  int Q;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int t;
    cin >> t;
    if(t == 1){
      int x;
      cin >> x;
      x--;
      for(int j=0; j<K; j++){
        cin >> P[x].c[j];
      }
      update(x);
    }
    else{
      int l, r;
      cin >> l >> r;
      l--; r--;
      node x = query(l, r);
      int res = 0;
      for(int y=0; y<32; y++){
        int j = 31 & (~y);
        res = max(res, dist(x.best[y], x.best[j]));
      }
      cout << res << "\n";
    }
  }

  return 0;
}