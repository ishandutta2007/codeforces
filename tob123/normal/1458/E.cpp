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

const int n = 1e5+10;

bool res[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<pii> a(N);
  vector<tuple<int,int,int>> b(M);
  for(int i=0; i<N; i++){
    cin >> a[i].first >> a[i].second;
  }
  for(int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    b[i] = make_tuple(x, y, i);
  }
  a.emplace_back(0, 0);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  set<int> ypos;
  int ycnt = 0;
  int ai = 0, bi=0;
  int lstX = -1;
  int lastYVis = -1;
  while(ai < sz(a) || bi < sz(b)){
    int x = -1;
    if(ai == sz(a)) x = get<0>(b[bi]);
    else if(bi == sz(b)) x = a[ai].first;
    else x = min(a[ai].first, get<0>(b[bi]));
    set<int> curA;
    while(ai < sz(a) && a[ai].first == x){
      curA.insert(a[ai++].second);
    }

    //cout << "ycnt: " << ycnt << ", lstX: " << lstX << endl;
    ycnt += x-lstX-1;
    auto it = ypos.lower_bound(lastYVis+1);
    while(it != ypos.end() && *it <= ycnt){
      lastYVis = *it;
      ycnt++; it++;
    }
    if(sz(curA) == 0 || ycnt < *(curA.begin())){
      curA.insert(ycnt);
    }
    //cout << "ycnt: " << ycnt << endl;

    while(bi < sz(b) && get<0>(b[bi]) == x){
      if(curA.count(get<1>(b[bi]))){
        res[get<2>(b[bi])] = false;
      }
      else{
        if(get<1>(b[bi]) < ycnt || (curA.size()>0 && *curA.begin() < get<1>(b[bi])) || ypos.count(get<1>(b[bi]))){
          res[get<2>(b[bi])] = true;
        }
        else{
          res[get<2>(b[bi])] = false;
        }
      }
      bi++;
    }
    //cout << "ycnt: " << ycnt << endl;

    for(int y : curA){
      ypos.insert(y);
    }
    it = ypos.lower_bound(lastYVis+1);
    while(it != ypos.end() && *it < ycnt){
      lastYVis = *it;
      it++;
    }

    /*
    cout << x << " " << lstX << " " << ycnt << "\nypos: ";
    for(int y : ypos)
      cout << y << " ";
    cout << endl;
    for(int y : curA)
      cout << y << " ";
    cout << endl << endl;
    */
    lstX = x;
  }
  for(int i=0; i<M; i++){
    if(res[i]){
      cout << "WIN\n";
    }
    else{
      cout << "LOSE\n";
    }
  }
}