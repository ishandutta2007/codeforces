#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> p;

int main(){
  cin >> N;
  p.resize(N/2);
  for(int i=0; i<N/2; i++){
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int s1=0, s2=0;
  for(int i=0; i<N/2; i++){
    s1 += abs(p[i] - (2*i+1));
    s2 += abs(p[i] - (2*i+2));
  }

  cout << min(s1, s2) << endl;

  return 0;
}