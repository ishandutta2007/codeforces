#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a,b,x=0,y=0,z=0,i;
    cin>>a>>b;
    for(i=1;i<=6;i++)
    {if (abs(a-i)<abs(b-i)) x++;
    if (abs(a-i)==abs(b-i)) y++;
    if (abs(a-i)>abs(b-i)) z++;}
    cout<<x<<" "<<y<<" "<<z;
}