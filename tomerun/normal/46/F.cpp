#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include "myutil.hpp"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll INF = 1 << 30;
int N,M,K;

struct UnionFind {
  vi set_;
  UnionFind(int size) : set_(size, -1){ }

  void add(int a, int b) {
    int rtA = root(a);
    int rtb = root(b);
    if (rtA == rtb) {
      return;
    }
    set_[rtA] += set_[rtb];
    set_[rtb] = rtA;
  }

  bool find(int a, int b) { return root(a) == root(b); }
  
  int root(int a) {
    if (set_[a] < 0) {
      return a;
    } else {
      set_[a] = root(set_[a]);
      return set_[a];
    }
  }
  
  int size(int a) { return -set_[root(a)]; }
};

vector<pair<int, int> > doors;
vi key2room1;
map<string, int> names1;
vi key2room2;
map<string, int> names2;

bool solve(vi& key2room, map<string, int>& names, vi& key2roomDst, map<string, int>& namesDst){
  UnionFind uf(N);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      int f = doors[j].first;
      int t = doors[j].second;
      if(uf.find(f,t)) continue;
      int room = key2room[j];
      if(uf.find(room, f) || uf.find(room, t)){
    uf.add(f,t);
      }
    }
  }
  for(int i = 0; i < M; ++i){
    if(!uf.find(key2room[i], key2roomDst[i])){
      return false;
    }
  }
  for(map<string,int>::iterator itr = names.begin(); itr != names.end(); ++itr) {
    string name = itr->first;
    int room= itr->second;
    if(!uf.find(room, namesDst[name])){
      return false;
    }
  }
  return true;
}

int main(){
  cin >> N >> M >> K;
  int from,to;
  for(int i = 0; i < M; ++i) {
    scanf("%d%d", &from, &to);
    doors.push_back(make_pair(from-1, to-1));
  }
  key2room1.resize(M);
  key2room2.resize(M);
  char name[20];
  int room, keyC, keyI;
  for(int i = 0; i < K; ++i) {
    scanf("%s%d%d", name, &room, &keyC);
    --room;
    names1.insert(make_pair(string(name), room));
    for(int j = 0; j < keyC; ++j){
      scanf("%d", &keyI);
      --keyI;
      key2room1[keyI] = room;
    }
  }
  for(int i = 0; i < K; ++i) {
    scanf("%s%d%d", name, &room, &keyC);
    --room;
    names2.insert(make_pair(string(name), room));
    for(int j = 0; j < keyC; ++j){
      scanf("%d", &keyI);
      --keyI;
      key2room2[keyI] = room;
    }
  }
  bool result = solve(key2room1, names1, key2room2, names2) && solve(key2room2, names2, key2room1, names1);
  cout << (result ? "YES" : "NO") << endl;
  return 0;
}