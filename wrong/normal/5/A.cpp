#include<iostream>
#include<string>

using namespace std;

int main()
{
  int persons = 0, sol = 0;
  string inp;
  while(getline(cin, inp)) {
    if(inp[0] == '+') persons++;
    else if(inp[0] == '-') persons--;
    else {
      int pos = inp.find_first_of(":");
      sol += persons * (inp.length() - pos - 1);
    }
  }
  cout << sol << endl;
  return 0;
}