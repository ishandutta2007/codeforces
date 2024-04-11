#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> par(n),child(n,0),num(n,0);
  for(int i=1;i<n;i++){
    cin >> par[i];
    par[i]--;
    child[par[i]]++;
  }
  queue<int> bfs;
  for(int i=0;i<n;i++){
    if(child[i]==0){
      bfs.push(i);
      num[i]=1;
    }
  }
  int now;
  while(!bfs.empty()){
    now=bfs.front();
    bfs.pop();
    if(now!=0){
      child[par[now]]--;
      num[par[now]]+=num[now];
      if(child[par[now]]==0){
        bfs.push(par[now]);
      }
    }
  }
  sort(num.begin(),num.end());
  for(int i=0;i<n;i++){
    cout << num[i] << " ";
  }
  cout << endl;
  return 0;
}