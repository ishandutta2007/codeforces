#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int N;
ll A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  ll s[] = {0,0};
  for(int i=0; i<N; i++){
    cin >> A[i];
    s[i%2] += (A[i]+1)/2;
    s[1-i%2] += A[i]/2;
  }
  cout << min(s[0], s[1]) << endl;

  return 0;
}