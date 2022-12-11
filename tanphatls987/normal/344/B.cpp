#include <iostream>

using namespace std;

int main()
{
    long int a,b,c,x,y,z;
    cin>>a>>b>>c;
    z=a-b+c;x=a+b-c;y=-a+b+c;
    if ((x%2)||(x<0)||(y%2)||(y<0)||(z%2)||(z<0)){cout<<"Impossible";return 0;}
    cout<<x/2<<" "<<y/2<<" "<<z/2;
}