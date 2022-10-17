#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> p(n/2);
  int black=0,white=0;
  for(int i=0;i<n/2;i++){
    cin >> p[i];
    p[i]--;
  }
  sort(p.begin(),p.end());
  for(int i=0;i<n/2;i++){
    black+=max(2*i-p[i],p[i]-2*i);
    white+=max(2*i+1-p[i],p[i]-2*i-1);
  }
  cout << min(black,white) << endl;
  return 0;
}