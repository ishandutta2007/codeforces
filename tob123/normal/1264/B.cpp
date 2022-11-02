#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int a[4];
vector<int> res;

void printRes(){
  bool f = true;
  for(int i=0; i<4; i++)
    f &= a[i] == 0;
  if(f){
    cout << "YES\n";
    for(int x : res){
      cout << x << " ";
    }
    cout << "\n";
  }
  else{
    cout << "NO\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int i=0; i<4; i++){
    cin >> a[i];
  }
  if(a[0] > a[1]){
    res.push_back(0);
    for(int i=0; i<a[1]; i++){
      res.push_back(1);
      res.push_back(0);
    }
    a[0] -= a[1];
    a[0]--;
    a[1] = 0;
    printRes();
    return 0;
  }
  if(a[3] > a[2]){
    res.push_back(3);
    for(int i=0; i<a[2]; i++){
      res.push_back(2);
      res.push_back(3);
    }
    a[3] -= a[2];
    a[3]--;
    a[2] = 0;
    printRes();
    return 0;
  }
  if(a[0] == a[1]){
    for(int i=0; i<a[1]; i++){
      res.push_back(0);
      res.push_back(1);
    }
    a[0] = 0;
    a[1] = 0;
    for(int i=0; i<a[3]; i++){
      res.push_back(2);
      res.push_back(3);
    }
    a[2] -= a[3];
    a[3] = 0;
    if(a[2]){
      res.push_back(2);
      a[2]--;
    }
    printRes();
    return 0;
  }
  if(a[2] == a[3]){
    for(int i=0; i<a[2]; i++){
      res.push_back(3);
      res.push_back(2);
    }
    a[3] = 0;
    a[2] = 0;
    for(int i=0; i<a[0]; i++){
      res.push_back(1);
      res.push_back(0);
    }
    a[1] -= a[0];
    a[0] = 0;
    if(a[1]){
      res.push_back(1);
      a[1]--;
    }
    printRes();
    return 0;
  }
  if(abs((a[1]-a[0]) - (a[2]-a[3])) > 1){
    printRes();
    return 0;
  }
  if(a[1]-a[0] >= a[2]-a[3]){
    for(int i=0; i<a[0]; i++){
      res.push_back(1);
      res.push_back(0);
    }
    res.push_back(1);
    for(int i=0; i<a[3]; i++){
      res.push_back(2);
      res.push_back(3);
    }
    res.push_back(2);
    a[1] -= a[0];
    a[2] -= a[3];
    a[0] = 0;
    a[3] = 0;
    a[1]--; a[2]--;
    for(int i=0; i<a[2]; i++){
      res.push_back(1);
      res.push_back(2);
    }
    a[1] -= a[2];
    a[2] = 0;
    if(a[1]){
      res.push_back(1);
      a[1]--;
    }
    printRes();
    return 0;
  }
  else{
    for(int i=0; i<a[3]; i++){
      res.push_back(2);
      res.push_back(3);
    }
    res.push_back(2);
    for(int i=0; i<a[0]; i++){
      res.push_back(1);
      res.push_back(0);
    }
    res.push_back(1);
    a[1] -= a[0];
    a[2] -= a[3];
    a[2]-=2; a[1]--;
    a[0] = 0;
    a[3] = 0;
    res.push_back(2);
    for(int i=0; i<a[2]; i++){
      res.push_back(1);
      res.push_back(2);
    }
    a[2] = 0;
    a[1] = 0;
    printRes();
    return 0;
  }

  return 0;
}