#include <iostream>
#include <math.h>
#include <vector>

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
  std::vector<int> num;
  for(int i=0; i<n; i++){
	  int k;
	  cin >> k;
	  int p;
	  int flag=0;
	  for(int j=0; j<k; j++){
		  cin >> p;
		  if(v>p){
			  flag=1;
			  
		  }
	  }
	  ans+=flag;
	  if (flag) num.push_back(i+1);

  }
  cout << ans <<"\n";
  for(int i=0; i<num.size(); i++) cout<<num[i]<<" ";

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}