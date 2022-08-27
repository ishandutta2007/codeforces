#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int n,v;
  int ans=0;
  cin >> n >> v;
  std::vector<int> f(3003, 0);

  for(int i=0; i<n; i++){
	  int a,b;
	  cin >> a >> b;
	  f[a]+=b;
  }

  int left=0;
  int coll=0;
  for(int j=1; j<=3001; j++){
	  if(left>=v){
		  coll+=v;
		  left=f[j];
		  continue;
	  }
	  coll+=min(v, left+f[j]);
	  left=max(0, left+f[j]-v);

  }
  cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}