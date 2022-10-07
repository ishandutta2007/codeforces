#include<iostream>
using namespace std;
string s;
main(){
 cin>>s;
 if(s[0]>96) s[0]-=32;
 cout<<s;
}