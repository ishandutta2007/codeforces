//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  vector <string> M;
  int n;
  cin >> n;
  vector <int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  while(true)
  {
    if(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end()))
      break;
    int w = *max_element(a.begin(), a.end());
    int cou = 0;
    for(int i=0; i<n; i++)
      if(a[i] == w)
        cou++;
    if(3 <= cou and cou <= 5)
    {
      string row = "";
      for(int i=0; i<n; i++)
        row += (a[i] == w) ? a[i] = max(a[i]-1, 0), "1" : "0";
      M.push_back(row);
    }
    else
    {
      auto i = max_element(a.begin(), a.end()) - a.begin();
      int rem = a[i];
      a[i] = -1;
      auto j = max_element(a.begin(), a.end()) - a.begin();
      a[i] = rem;
      string row = "";
      for(int k=0; k<n; k++)
        row += (k == i or k == j) ? a[k] = max(a[k]-1, 0), "1" : "0";
      M.push_back(row);
    }
  }
  cout << *max_element(a.begin(), a.end()) << "\n";
  cout << (int)M.size() << "\n";
  for(auto ele : M)
    cout << ele << "\n";
  return 0;
}