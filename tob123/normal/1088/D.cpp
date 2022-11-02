#include <bits/stdc++.h>
using namespace std;

int ma = 0, mb = 0;
int N;

void solveLt();
void solveGt();
void solveEq();

int ask(int c, int d){
  int askc = (c<<N) | (ma << (N+1));
  int askd = (d<<N) | (mb << (N+1));
  cout << "? " << askc << " " << askd << endl;
  int res;
  cin >> res;
  return res;
}

void addM(int a, int b){
  ma <<= 1;
  mb <<= 1;
  ma |= a;
  mb |= b;
}

void solveGt(){
  if(N == 0)
    return;
  N--;
  int res1 = ask(1, 0);
  if(res1 == 1){
    int res2 = ask(0, 1);
    if(res2 == 1){
      addM(1, 0);
      solveGt();
    }
    else{
      addM(0, 0);
      solveGt();
    }
  }
  else if(res1 == 0){
    addM(1, 0);
    solveEq();
  }
  else{
    int res2 = ask(0, 1);
    if(res2 == 1){
      addM(1, 1);
      solveGt();
    }
    else{
      addM(1, 0);
      solveLt();
    }
  }
}

void solveLt(){
  if(N == 0)
    return;
  N--;
  int res1 = ask(0, 1);
  if(res1 == 1){
    int res2 = ask(1, 0);
    if(res2 == 1){
      addM(0, 1);
      solveGt();
    }
    else{
      addM(1, 1);
      solveLt();
    }
  }
  else if(res1 == 0){
    addM(0, 1);
    solveEq();
  }
  else{
    int res2 = ask(1, 0);
    if(res2 == 1){
      addM(0, 0);
      solveLt();
    }
    else{
      addM(0, 1);
      solveLt();
    }
  }
}

void solveEq(){
  if(N == 0)
    return;
  N--;
  if(ask(1, 0) == 1){
    addM(0, 0);
  }
  else{
    addM(1, 1);
  }
  solveEq();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  N = 30;
  int res = ask(0,0);
  if(res == 1){
    solveGt();
  }
  else if(res == 0){
    solveEq();
  }
  else{
    solveLt();
  }
  cout << "! " << ma << " " << mb << endl;

  return 0;
}