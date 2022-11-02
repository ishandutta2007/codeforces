#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int sz = 2e5+10;
ll BIT[3][sz];
vector<int> P;
vector<pii> A;
ll res[sz];
int N;

void update(int ind, int y, ll val){ // adds val to entry x (0-based)
  y++;
  while(y <= sz){
    BIT[ind][y] += val;
    y += y & (-y);
  }
}

ll query(int ind, int x){ // returns sum of all elements 0..x
  x++;
  ll res = 0;
  while(x > 0){
    res += BIT[ind][x];
    x -= x & (-x);
  }
  return res;
}

const int sz2 = 1024*256*2;
//const int sz2 = 8*;
const int offset = sz2/2-1;
ll S[2][sz2];
ll L[2][sz2];

void printSeg(int s){
  int p = 2;
  for(int i=0; i<sz2; i++){
    if(i+1 == p){
      cout << "\n";
      p *= 2;
    }
    cout << S[s][i] << " ";
  }
  cout << endl;
}

int par(int x){ return (x-1)/2;}
int left(int x){ return 2*x+1;}
int right(int x){ return 2*x+2;}

void prop(int s, int cur, int si){
  if(cur < offset){
    S[s][left(cur)] += L[s][cur]*si/2;
    S[s][right(cur)] += L[s][cur]*si/2;
    L[s][left(cur)] += L[s][cur];
    L[s][right(cur)] += L[s][cur];
    L[s][cur] = 0;
  }
}

void upd(int s, int l, int r, int curl=0, int curr=offset, int cur=0){
  prop(s, cur, curr-curl+1);
  if(l > curr || r < curl)
    return;
  if(l <= curl && r >= curr){
    L[s][cur]++;
    S[s][cur] += curr-curl+1;
    return;
  }
  int m = (curl+curr)/2;
  upd(s, l, r, curl, m, left(cur));
  upd(s, l, r, m+1, curr, right(cur));
  S[s][cur] = S[s][left(cur)] + S[s][right(cur)];
}

ll qry(int s, int l, int r, int curl=0, int curr=offset, int cur=0){
  prop(s, cur, curr-curl+1);
  if(l > curr || r < curl)
    return 0;
  if(l <= curl && r >= curr){
    return S[s][cur];
  }
  int m = (curl+curr)/2;
  return qry(s, l, r, curl, m, left(cur))
        + qry(s, l, r, m+1, curr, right(cur));
}

set<int> A1, B;
int median(int x){
  if(B.size() == 0){
    B.insert(x);
    return x;
  }
  else{
    int m = *(B.begin());
    if(x < m){
      A1.insert(x);
    }
    else{
      B.insert(x);
    }
    if(sz(A1) > sz(B)){
      auto it = A1.end();
      it--;
      B.insert(*it);
      A1.erase(it);
    }
    else if(sz(B) > sz(A1)+1){
      int m = *(B.begin());
      B.erase(B.begin());
      A1.insert(m);
    }
    return *(B.begin());
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  P.resize(N);
  for(int i=0; i<N; i++){
    cin >> P[i];
    P[i]--;
    A.push_back(make_pair(P[i], i));
  }
  sort(A.begin(), A.end());
  int r = 0;
  int l = N+1;
  for(int i=0; i<N; i++){
    int val, ind;
    tie(val,ind) = A[i];
    r = max(r, ind); l = min(l, ind);
    res[i] += i-query(0, ind);
    res[i+1] = res[i];
    update(0, ind, 1);
    int m = median(ind);
    //cout << "med: " << m << endl;
    //cout << "upd 0 " << ind << " " << N+10 << endl;
    upd(0, ind, N+10);
    //cout << "upd 1 " << 0 << " " << ind << endl;
    upd(1, 0, ind);
    res[i] += qry(0, l, m-1) + qry(1, m, r);
    //printSeg(0);
    //cout << "qry0: " << l << " " << m-1 << ": " << qry(0, l, m-1) << endl;
    //cout << "qry1: " << qry(1, m, r) << endl;
    ll ls = (i+1)/2;
    ll rs = (i+2)/2;
    //cout << "abz l: " << ls*(ls+1)/2 << endl;
    //cout << "abz r: " << rs*(rs+1)/2 << endl;
    res[i] -= ls*(ls+1)/2 + rs*(rs+1)/2;

    //cout << endl;
  }
  for(int i=0; i<N; i++){
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}