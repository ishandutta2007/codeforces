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
int m,n;
cin >> n >> m;
char c;
///int i,j;
for (int j=0; j<n; j++){
for(int i=0; i<m; i++){
	cin >> c;
	if(c==45) cout<<"-";
	else if ((i+j)/2*2==(i+j)) cout<<"B";
	else cout<<"W";}
//
cout<<"\n";
//scanf("\n");
}


  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}