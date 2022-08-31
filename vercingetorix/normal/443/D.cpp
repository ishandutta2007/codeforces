#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n;
  cin >> n;
  double p;
  std::vector<double> f(n,0);

  for(int i=0; i<n; i++){
	  cin>>p;
	  f[i]=p;
  }
  std::sort(f.begin(), f.end());


  double pp=0, p1=0;
  for(int i=n-1; i>=0; i--){
	  double q=f[i];
	  p1=p1*(1-q)+(1-pp)*q;
	  pp=pp+q-pp*q;
	  if((p1+pp)>=1) break;
  }
  printf("%.10f", p1);
  return 0;
}