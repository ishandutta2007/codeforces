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
  int n,p;
cin >> p >> n;
std::vector<int> a;
for(int i=0;i<n;i++){
    int x;
    cin >>x;
    //xp;
    for(int j=0; j<a.size();j++){
        if(x%p==a[j]){
            cout<<(i+1);
            return 0;
        }
    }
    a.push_back(x%p);

}
cout<< -1;
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}