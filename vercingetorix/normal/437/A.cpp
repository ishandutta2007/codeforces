#include <iostream>
#include <math.h>
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
  int n,d;
  char c;
  int ans=0;
  std::string s;
  int a[4];
  //cin >> n >> d;
  for(int i=0; i<4;i++){
	  cin>>c;
	  cin>>c;
	  cin>>s;
	  a[i]=s.length();
  }
  int amin=101;
  int imin, imax;
  int amax=-1;
  for(int j=0;j<4;j++){
	  if(a[j]>amax){
		  imax=j;
		  amax=a[j];
	  }
	  if(a[j]<amin){
		  imin=j;
		  amin=a[j];
	  }
  }
  bool gmax=true, gmin=true;
  for(int j=0; j<4;j++){
	  if((j!=imin)&&(amin*2>a[j])) gmin=false;
	  if((j!=imax)&&(amax<2*a[j])) gmax=false;
  }
  if(gmax&&gmin){
  cout<<"C"; return 0;}

  
  if((!gmax)&&(!gmin)){
  cout<<"C"; return 0;}
  
  if(gmax){
	  if(imax==0) cout<<"A";
	  if(imax==1) cout<<"B";
	  if(imax==2) cout<<"C";
	  if(imax==3) cout<<"D";
	  return 0;
  }
	if(imin==0) cout<<"A";
	  if(imin==1) cout<<"B";
	  if(imin==2) cout<<"C";
	  if(imin==3) cout<<"D";

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}