#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  long long n,x;
  long long ans=0;
  cin >> n >> x;
  std::vector<long long> f;
  for(int i=0; i<n; i++){
	  int c;
	  cin  >> c;
	  f.push_back(c);
  }
  std::sort(f.begin(), f.end());

  for(int i=0; i<n; i++){
	  ans+=x*f[i];
	  if(x>1) x--;
  }
  
  cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}