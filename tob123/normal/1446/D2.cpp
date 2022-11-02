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

const int n = 200200;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N+1);
  vector<int> cnt(N);
  for(int i=1; i<=N; i++){
    cin >> A[i];
    A[i]--;
    cnt[A[i]]++;
  }
  int maxE = max_element(cnt.begin(), cnt.end())-cnt.begin();
  int SQRT = (int) sqrt(N);
  vector<int> cols;
  for(int i=0; i<N; i++){
    if(cnt[i] >= SQRT-1 && i != maxE){
      cols.push_back(i);
    }
  }
  int bst = 0;
  for(int c : cols){
    int cnt1 = 0, cnt2 = 0;
    vector<int> res;
    res.push_back(0);
    for(int i=1; i<=N; i++){
      if(A[i] == c)
        cnt1++;
      else if(A[i] == maxE)
        cnt2++;
      if(cnt2-cnt1 == sz(res))
        res.push_back(i);
      if(cnt2 >= cnt1 && cnt2-cnt1 < sz(res)){
        bst = max(bst, i-res[cnt2-cnt1]);
      }
    }
  }

  vector<int> pos;
  pos.push_back(0);
  for(int i=1; i<=N; i++){
    if(A[i] == maxE){
      pos.push_back(i);
    }
  }
  cnt.clear();
  cnt.resize(N);
  for(int p : pos){
    int curMx = 0;
    //print(cnt);
    int endP = 0;
    for(int i=p+1; i<=N; i++){
      endP = i;
      cnt[A[i]]++;
      if(A[i] != maxE)
        curMx = max(curMx, cnt[A[i]]);
      if(curMx == cnt[maxE]){
        bst = max(bst, i-p);
      }
      if(cnt[maxE] > SQRT)
        break;
    }
    //print(cnt);
    for(int i=p+1; i<=endP; i++){
      cnt[A[i]]--;
    }
  }

  cout << bst << endl;
}