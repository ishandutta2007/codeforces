#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int m,n;
  cin>>n;
  string s;
  getline(cin,s);
  vvi mat(n+1);
  int trace=0;
  for(int i=0; i<n; i++){
      
      getline(cin,s);
      trace+=s[2*i];
  }
  trace=trace%2;
  int q,t,l;
  cin>>q;
  for(int j=0;j<q;j++){
      scanf("%d",&t);
      if(t==3) printf("%d",trace);
      else {
          trace=1-trace;
          scanf("%d",&t);
      }
  }

  return 0;
}