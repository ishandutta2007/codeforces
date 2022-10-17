#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  if(n==1){
    cin >> n;
    cout << "Yes" << endl;
    return 0;
  }
  vector<list<int>> e(n);
  int x,y;
  for(int i=0;i<n-1;i++){
    cin >> x >> y;
    e[--x].push_back(--y);
    e[y].push_back(x);
  }
  vector<int> parent(n,-1);
  queue<int> bfs;
  parent[0]=0;
  bfs.push(0);
  int now=0;
  while(!bfs.empty()){
    now=bfs.front();
    bfs.pop();
    for(auto i:e[now]){
      if(parent[i]<0) parent[i]=now,bfs.push(i);
    }
  }
  int a;
  cin >> a;
  a--;
  if(a!=0){
    cout << "No" << endl;
    return 0;
  }
  queue<int> p;
  p.push(0);
  vector<bool> used(n,false);
  used[0]=true;
  for(int i=1;i<n;i++){
    cin >> a;
    a--;
    while(p.front()!=parent[a]){
      p.pop();
      if(p.empty()){
        cout << "No" << endl;
        return 0;
      }
    }
    used[a]=true;
    p.push(a);
  }
  for(int i=0;i<n;i++) if(!used[i]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}