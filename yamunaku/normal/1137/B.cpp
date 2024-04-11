#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,t;
  cin >> s >> t;
  int n=s.size(),m=t.size();
  vector<int> A(m);
  A[0] = m;
  int i = 1, j = 0;
  while (i < t.size()) {
    while (i+j < t.size() && t[j] == t[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < t.size() && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
  int count[2]={0,0};
  for(int i=0;i<n;i++){
    count[s[i]-'0']++;
  }
  int x=m;
  for(int i=1;i<m;i++){
    if(A[i]==m-i){
      x=i;
      break;
    }
  }
  // cout << x << endl;
  int p[2]={0,0},q[2]={0,0};
  for(int i=0;i<x;i++){
    p[t[i]-'0']++;
  }
  for(int i=x;i<m;i++){
    q[t[i]-'0']++;
  }
  if(count[0]<q[0]||count[1]<q[1]){
    for(int i=0;i<count[0];i++){
      cout << "0";
    }
    for(int i=0;i<count[1];i++){
      cout << "1";
    }
    cout << endl;
    return 0;
  }
  count[0]-=q[0];
  count[1]-=q[1];
  // cout << count[0] SP count[1] << endl;
  // cout << t.substr(x,t.length()-x) << endl;
  string ans="";
  string aa=t.substr(0,x),bb=t.substr(x,t.length()-x);
  while(count[0]>=p[0]&&count[1]>=p[1]){
    count[0]-=p[0];
    count[1]-=p[1];
    // cout << count[0] SP count[1] << endl;
    ans+=aa;
  }
  // cout << ans << endl;
  ans+=bb;
  cout << ans;
  for(int i=0;i<count[0];i++){
    cout << "0";
  }
  for(int i=0;i<count[1];i++){
    cout << "1";
  }
  cout << endl;
  return 0;
}