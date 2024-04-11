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

const int n = 5e5;

bool inS[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<2*N; i++)
      inS[i] = false;
    vector<int> b(N), a, toL(N), toR(N);
    for(int i=0; i<N; i++){
      cin >> b[i];
      b[i]--;
      inS[b[i]] = true;
    }
    for(int i=0; i<2*N; i++){
      if(!inS[i])
        a.push_back(i);
    }
    int pi = 0;
    for(int i=0; i<N; i++){
      while(pi < N && a[pi] < b[i])
        pi++;
      toL[i] = N-pi+i;
      if(i > 0)
        toL[i] = min(toL[i], toL[i-1]);
    }
    pi = N-1;
    for(int i=N-1; i>=0; i--){
      while(pi>=0 && a[pi] > b[i])
        pi--;
      toR[i] = pi+1+(N-i-1);
      if(i < N-1)
        toR[i] = min(toR[i], toR[i+1]);
    }
    /*
    print(a);
    print(b);
    print(toL);
    print(toR);
    */
    int res = 0;
    if(toR[0] >= N)
      res++;
    if(toL[N-1] >= N)
      res++;
    for(int i=0; i<N-1; i++){
      if(toL[i] >= i+1 && toR[i+1] >= N-i-1)
        res++;
    }
    cout << res << "\n";
  }
}