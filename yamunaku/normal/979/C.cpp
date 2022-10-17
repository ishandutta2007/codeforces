#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct joutai{
  int num;
  int fb;
};

int main(){
  LL n;
  int x,y;
  cin >> n >> x >> y;
  x--;
  y--;
  vector<list<int>> e(n,list<int>());
  int a,b;
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  vector<int> FB(n,0);
  vector<int> ok(n,0);
  queue<struct joutai> dfs;
  struct joutai now;
  dfs.push({x,1});
  while(!dfs.empty()){
    now=dfs.front();
    dfs.pop();
    FB[now.num]=now.fb;
    for(list<int>::iterator itr=e[now.num].begin();itr!=e[now.num].end();itr++){
      if(ok[(*itr)]==0){
        if(now.num==y){
          dfs.push({(*itr),0});
          ok[(*itr)]++;
        }else{
          dfs.push({(*itr),now.fb});
          ok[(*itr)]++;
        }
      }
    }
  }
  dfs.push({y,2});
  while(!dfs.empty()){
    now=dfs.front();
    dfs.pop();
    if(now.fb==2){
      if(FB[now.num]){
        FB[now.num]=0;
      }else{
        FB[now.num]=2;
      }
    }
    for(list<int>::iterator itr=e[now.num].begin();itr!=e[now.num].end();itr++){
      if(ok[(*itr)]==1){
        if(now.num==x){
          dfs.push({(*itr),1});
          ok[(*itr)]++;
        }else{
          dfs.push({(*itr),now.fb});
          ok[(*itr)]++;
        }
      }
    }
  }
  FB[x]=1;
  FB[y]=2;
  LL F=0,B=0;
  for(int i=0;i<n;i++){
    if(FB[i]==1){
      F++;
      //cout << "F ";
    }else if(FB[i]==2){
      B++;
      //cout << "B ";
    }else{
      //cout << "N ";
    }
  }
  //cout << endl;
  cout << n*(n-1)-F*B << endl;
  return 0;
}