//CF 5B
#include<iostream>
#include<string>

using namespace std;

inline int max(int a, int b) {return a < b ? b : a;}

int top, l, t1, t2, t3, rev;
string s, ar[1005];

int main() {
  while (getline(cin, s)) {
    ar[++top] = s;
    l = max(l, s.size());
  }
  l = l + 2;
  for (int i = 1; i <= l; i++) cout<<"*";
  cout<<endl;
  rev = 0;
  for (int i = 1; i <= top; i++) {
    cout<<"*";
    t1 = l - ar[i].size() - 2;
    t2 = t3 = t1 / 2;
    if (t1 % 2) {
      if (rev) {
        t2++;
        rev = 0;
      } else {
        t3++;
        rev = 1;
      }
    }
    for (int j = 1; j <= t2; j++) cout<<" ";
    cout<<ar[i];
    for (int j = 1; j <= t3; j++) cout<<" ";
    cout<<"*"<<endl;
  }
  for (int i = 1; i <= l; i++) cout<<"*";
  cout<<endl;
    
  return 0;
}