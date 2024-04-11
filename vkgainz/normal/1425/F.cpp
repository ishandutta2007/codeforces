#include <bits/stdc++.h>
using namespace std;
int query(int l,int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int main() {
  int N; cin >> N;
  vector<int> pos(N);
  for(int i=0;i<N-1;i++) {
    pos[i] = query(i+1, i+2);
  }
  pos[N-1] = query(1, 3);
  vector<int> a(N);
  a[0] = pos[N-1] - pos[1];
  for(int i=1;i<N;i++) {
    a[i] = pos[i-1] - a[i-1];
  }
  cout << "! ";
  for(auto &a : a) {
    cout << a << " ";
  }
  cout << "\n";
  cout.flush();
}