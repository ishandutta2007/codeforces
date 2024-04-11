#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pi;

const int MAXN = 1e6+20;

int N;
vector<int> A;
vector<int> G[MAXN];
int C;
int D[MAXN], F[MAXN], Val[MAXN];

void printG(){
  for(int i=0; i<C; i++){
    cout << i << ":";
    for(int x : G[i])
      cout << " " << x;
    cout << endl;
  }
  cout << endl;
}

int bfs(int st){
  queue<int> Q;
  fill_n(D, C, -1);
  D[st] = 0; F[st] = -1;
  Q.push(st);
  int best = 1e8;
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(int x : G[cur]){
      if(x != F[cur]){
        if(D[x] == -1){
          D[x] = D[cur]+1;
          F[x] = cur;
          Q.push(x);
        }
        else{
          best = min(best, D[x]+D[cur]+1);
        }
      }
    }
  }
  return best;
}

int phi[2*MAXN], lp[2*MAXN];
vector<int> p;

//x = [0].first^[0].second * ...
vector<pair<int, int>> factorise(int x) {
	vector<pair<int, int>> d;
  if(x == 1) return d;
	int y = lp[x], a = 1;
	x /= lp[x];
	while (x > 1) {
		if (lp[x] != y) {
			d.push_back({y, a});
			y = lp[x]; a = 0;
		}
		x /= lp[x], a++;
	}
	d.push_back({y, a});
	return d;
}

void sieve(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (lp[i] == 0) {
			lp[i] = i; phi[i] = i - 1;
			p.push_back(i);
		} else if (lp[i] == lp[i / lp[i]])
			phi[i] = phi[i / lp[i]] * lp[i];
		else
			phi[i] = phi[i / lp[i]] * (lp[i] - 1);
		for (int j = 0; j < (int) p.size() && p[j] <= lp[i] && i * p[j] <= n; j++)
			lp[i * p[j]] = p[j];
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sieve(MAXN);
  map<int,int> M;
  vector<pi> E;
  for(int i=0; i<N; i++){
    vector<pi> res = factorise(A[i]);
    vector<int> r2;
    for(auto p : res)
      if(p.second%2)
        r2.push_back(p.first);
    if(sz(r2) == 0){
      cout << 1 << endl;
      return 0;
    }
    else if(sz(r2) == 1){
      r2.push_back(1);
    }
    if(sz(r2) == 2){
      for(int i=0; i<2; i++){
        if(!M.count(r2[i])){
          Val[C] = r2[i];
          M[r2[i]] = C++;
        }
      }
      E.push_back({min(r2[0], r2[1]), max(r2[0], r2[1])});
      G[M[r2[0]]].push_back(M[r2[1]]);
      G[M[r2[1]]].push_back(M[r2[0]]);
    }
    else{
      cerr << "fail" << endl;
      exit(1);
    }
  }
  sort(E.begin(), E.end());
  if(E.end()-unique(E.begin(), E.end())){
    cout << 2 << endl;
    return 0;
  }
  //printG();
  int m = 1e8;
  for(int i=0; i<C; i++){
    if(Val[i] <= 1000)
      m = min(m, bfs(i));
  }
  if(m == 1e8){
    cout << -1 << endl;
  }
  else
    cout << m << endl;

  return 0;
}