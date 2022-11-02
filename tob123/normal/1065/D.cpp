#include <bits/stdc++.h>
using namespace std;

set<tuple<int,int,int,int>> vis; //curFig, feld, y, x

struct El{
  int dist, wechsel, fig, feld, y, x;
  bool operator<(const El& e) const{
    return dist > e.dist || (dist == e.dist && wechsel > e.wechsel);
  }
  bool isVis(){
    return vis.count(make_tuple(fig, feld, y, x)) > 0;
  }
};

const int n = 20;

int N;
int A[n][n];
priority_queue<El> Q;
int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
  cin >> N;
  for(int i=2; i<N+2; i++){
    for(int j=2; j<N+2; j++){
      cin >> A[i][j];
      if(A[i][j] == 1){
        for(int x=0; x<3; x++){
          Q.push({0, 0, x, 1, i, j});
        }
      }
    }
  }

  while(!Q.empty()){
    El cur = Q.top();
    Q.pop();
    if(cur.isVis()){
      continue;
    }
    vis.insert(make_tuple(cur.fig, cur.feld, cur.y, cur.x));
    int y = cur.y, x = cur.x;
    if(cur.feld == N*N+1){
      cout << cur.dist << " " << cur.wechsel << endl;
      return 0;
    }
    if(A[y][x] == cur.feld){
      Q.push({cur.dist, cur.wechsel, cur.fig, cur.feld+1, y, x});
      continue;
    }
    for(int x=0; x<3; x++){
      Q.push({cur.dist+1, cur.wechsel+1, x, cur.feld, cur.y, cur.x});
    }
    if(cur.fig == 0){
      for(int cury=y, curx=x; A[cury][curx] != 0; cury++, curx++){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; cury--, curx++){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; cury--, curx--){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; cury++, curx--){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
    }
    else if(cur.fig == 1){
      for(int cury=y, curx=x; A[cury][curx] != 0; cury++){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; cury--){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; curx--){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
      for(int cury=y, curx=x; A[cury][curx] != 0; curx++){
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        Q.push(nel);
      }
    }
    else{
      for(int i=0; i<8; i++){
        int curx = x+X[i];
        int cury = y+Y[i];
        El nel = {cur.dist+1, cur.wechsel, cur.fig, cur.feld, cury, curx};
        if(A[cury][curx] != 0 && !nel.isVis())
          Q.push(nel);
      }
    }
  }

  return 0;
}