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


char c = 'a';
bool* l = new bool[26];
for(int i=0; i<26; i++) l[i]=false;

//
cin >> c;
//if (c!='}') l[c-97]=true;
while (c!='}'){
	cin >> c;
	if(c=='}') break;
	l[c-97]=true;
	cin >> c;
}
int n=0;
for(int i=0; i<26; i++) if(l[i]==true) n++;

cout << n;



  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}