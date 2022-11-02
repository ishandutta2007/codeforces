#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 2e5+10;

int N;
vector<int> G[n];
bool vis[n];
int D[n];
int S[n];
int P[n];

void printAll(){
  cout << "S: ";
  for(int i=1; i<=N; i++){
    cout << S[i] << " ";
  }
  cout << endl;
  cout << "D: ";
  for(int i=1; i<=N; i++){
    cout << D[i] << " ";
  }
  cout << endl;
  cout << "P: ";
  for(int i=1; i<=N; i++){
    cout << P[i] << " ";
  }
  cout << endl;
}

int askD(int x){
  int d;
  cout << "d " << x << endl;
  cin >> d;
  if(d == -1){
    exit(1);
  }
  return d;
}
int askS(int x){
  int d;
  cout << "s " << x << endl;
  cin >> d;
  if(d == -1){
    exit(1);
  }
  return d;
}

void dfs(int cur){
  vis[cur] = true;
  for(int x : G[cur]){
    if(!vis[x]){
      D[x] = D[cur]+1;
      dfs(x);
      S[cur] += S[x];
    }
    else{
      P[cur] = x;
    }
  }
  S[cur]++;
}

void remE(int from, int to, int toD){
  for(int i=0; i<sz(G[from]); i++){
    if(G[from][i] == to){
      G[from][i] = G[from][sz(G[from])-1];
      G[from].pop_back();
      S[from] -= S[to];
      break;
    }
  }
  while(from != 1){
    from = P[from];
    /*
    if(D[from] < toD)
      break;
      */
    S[from] -= S[to];
  }
}

int split(int cur, int d, int s){
  //cout << "split(" << cur << ", " << s << ")" << endl;
  if(d == 0)
    return cur;
  if(S[cur] <= min(s-1, (s+1)/2)){
    return cur;
  }
  int maxI = -1;
  int best = abs((s+1)/2 - S[cur]);
  for(int i=0; i<sz(G[cur]); i++){
    if(G[cur][i] == P[cur])
      continue;
    if(abs((s+1)/2 - S[G[cur][i]]) < best){
      maxI = i;
      best = abs((s+1)/2 - S[G[cur][i]]);
    }
  }
  if(maxI == -1)
    return cur;
  else
    return split(G[cur][maxI], d-1, s);
}

void search(int cur, int d){
  int par = P[cur];
  if(d == 0){
    cout << "! " << cur << endl;
    return;
  }
  int maxI = -1;
  for(int x : G[cur]){
    if(S[x] >= (S[cur]+1)/2 && x != P[cur])
      maxI = x;
  }
  //cout << "maxI: " << maxI << endl;
  if(maxI == -1){
    int nxt = askS(cur);
    search(nxt, d-1);
  }
  else{
    int s = split(cur, d, S[cur]);
    //cout << "s: " << s << endl;
    int dist = askD(s);
    if(dist == (d + D[s]-D[cur])){
      remE(cur, maxI, D[cur]);
      search(cur, d);
    }
    else if(dist == (d - (D[s]-D[cur]))){
      //cout << "nw rt: " << s << endl;
      search(s, dist);
    }
    else{
      remE(P[s], s, D[maxI]);
      search(maxI, d-1);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  //printAll();
  int d = askD(1);
  search(1, d);

  return 0;
}