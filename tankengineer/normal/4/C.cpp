#include<iostream>
#include<map>
using namespace std;

int n, t1;
string s;
map<string, int> dict;
map<string, int>::iterator t;

int main() {
  cin>>n;
  for (; n; n--) {
    cin>>s;
    t = dict.find(s);
    if (t == dict.end()) {
      cout<<"OK"<<endl;
      dict.insert(make_pair(s, 0));
    } else {
      t->second++;
      cout<<s<<t->second<<endl;
    } 
  }
  return 0;
}