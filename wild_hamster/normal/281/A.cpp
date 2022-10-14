#include <iostream>
using namespace std;
int main()
{
char s[10000];
cin>>s;
if (s[0]>=97) s[0]=s[0]-32;
cout<<s;
return 0;
}