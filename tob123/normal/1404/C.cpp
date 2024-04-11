#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 3e5+10;

int N, Q;
int A[n];

const int ssize = 1024*1024;
const int offset = ssize/2-1;

int S[ssize];
int U[ssize];

void upd(int l, int r, int curl=0, int curr=offset, int cur=0){
  if(l <= curl && r >= curr){
    U[cur]++;
    S[cur]++;
    return;
  }
  if(l > curr || r < curl)
    return;
  int m = (curl+curr)/2;
  upd(l, r, curl, m, 2*cur+1);
  upd(l, r, m+1, curr, 2*cur+2);
  S[cur] = max(S[2*cur+1], S[2*cur+2]) + U[cur];
}

int query(int x){
  x += offset;
  int res = U[x];
  while(x > 0){
    x = (x-1)/2;
    res += U[x];
  }
  return res;
}

int query2(int val, int curl=0, int curr=offset, int cur=0){
  if(curl == curr)
    return curl;
  val -= U[cur];
  int m = (curl+curr)/2;
  if(S[2*cur+2] >= val)
    return query2(val, m+1, curr, 2*cur+2);
  else
    return query2(val, curl, m, 2*cur+1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i]--;
  }
  vector<vector<pii>> qry(N);
  for(int i=0; i<Q; i++){
    int x, y;
    cin >> x >> y;
    qry[N-y-1].emplace_back(x, i);
  }
  vector<int> res(Q);
  for(int i=0; i<N; i++){
    //cout << "going " << i << " ... " << A[i] << endl;
    if(A[i] < i){
      if(S[0] >= i-A[i]){
        int ind = query2(i-A[i]);
        //cout << "query2 " << i-A[i] << " -> " << ind << endl;
        upd(0, ind);
        //cout << "upd " << ind << endl;
      }
    }
    else if(A[i] == i){
      upd(0, i);
      //cout << "upd " << i << endl;
    }
    for(auto[x, ind] : qry[i]){
      res[ind] = query(x);
      //cout << ind << ": " << res[ind] << endl;
    }
  }
  for(int i=0; i<Q; i++){
    cout << res[i] << "\n";
  }
}