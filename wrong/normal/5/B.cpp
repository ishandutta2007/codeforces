#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
  vector<string> inp;
  string tmp;
  while(getline(cin, tmp)) inp.push_back(tmp);
  int maxlen = 0;
  for(int i=0; i<inp.size(); ++i)
    maxlen = max(maxlen, (int)inp[i].length());
  for(int i=0; i<maxlen+2; ++i) cout << "*";
  cout << endl;
  int left = 0;
  for(int i=0; i<inp.size(); ++i) {
    cout << "*";
    int rem = maxlen-inp[i].size();
    int add = 0;
    if(rem % 2 != 0) {
      add = left;
      left = 1 - left;
    }
    for(int j=0; j<rem/2+add; ++j) cout << " ";
    cout << inp[i];
    for(int j=rem/2+add; j<rem; ++j) cout << " ";
    cout << "*" << endl;
  }
  for(int i=0; i<maxlen+2; ++i) cout << "*";
  cout << endl;
  return 0;
}