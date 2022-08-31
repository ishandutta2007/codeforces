#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

double deg(double p, int n){
	double pc=p;
	double ans=1;
	int nc=n;
	while(nc>0){
		if((nc%2)==1) ans*=pc;
		nc/=2;
		pc*=pc;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,m;
  cin>>m>>n;
  char c;

  double ME=m;
  std::vector<std::string> s;
 for(int i=1; i<=(m-1); i++){
	  double p=(double)(i)/(double)(m);
	  ME-=deg(p,n);
 }
  printf("%.10f", ME);
//std::vector<int> a;

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */
 //cout<<deg(2.,7);
  return 0;
}