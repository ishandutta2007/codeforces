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
 cin >> n;
 int c1=0, c2=0;
 for(int i=0; i<n;i++){
	 cin>>d;
	 if(d==100) c1++;
	 else c2++;
 }

 if(c1%2==1){
	 cout<<"NO";
		 return 0;
 }
 else{
	 if(c2%2==0){
		 cout<<"YES";
		 return 0;

	 }
	 else{
		 if(c1>0){
			 cout<<"YES";
			 return 0;
		 }
		 cout<<"NO";
		 return 0;
	 }

 }


  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}