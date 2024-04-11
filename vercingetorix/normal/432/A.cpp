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

  int n,k;
  cin>>n>>k;

std::vector<int> a;
std::string s;
int ans=0;
for(int i=0;i<n;i++){
    int x;
    cin >>x;
    if((5-x)>=k) ans++;
    a.push_back(x);
    //xp;


}
//char c;

cout<< ans/3;
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}