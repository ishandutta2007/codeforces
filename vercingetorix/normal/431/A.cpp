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
  int a1,a2,a3,a4;
//cin >> a1>>a2>>a3>>a4;
std::vector<int> a;
std::string s;
int ans=0;
for(int i=0;i<4;i++){
    int x;
    cin >>x;
    a.push_back(x);
    //xp;


}
//char c;
cin>>s;
for(int i=0; i<s.length();i++){
  //  cout<<s[i]-'1'<<endl;
    ans+=a[s[i]-'1'];
}
cout<< ans;
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}