#include <iostream>
using namespace std;
int main()
{
int a1,a2,res;
cin>>a1>>a2;
res=0;
while (a2!=0) {res*=10;res=(res+a2%10);a2/=10;}
cout<<res+a1;
return 0;
}