#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
typedef long long ll;
const ll mod=1000000007;

int main(){
  string s;
  cin>>s;
  cout<<s;
  reverse(s.begin(),s.end());
  cout<<s<<endl;
  return 0;        
  }