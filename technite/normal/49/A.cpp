#include <iostream>
#include <string>
using namespace std;
int main(){
int i;
string s,s0="eyuioaEYUIOA";
getline(cin,s);
i=s.size()-2;
while(s[i]==' ') i--;
 cout<<(s0.find(s[i])!=string::npos?"YES":"NO");
}