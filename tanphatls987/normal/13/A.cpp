#include <iostream>
#include <fstream>
using namespace std;

int n,x,y,tmpn,red,tmp,i;
int gcd(int x,int y)
{
    while (y)
    {
        tmp=y;y=x%y;x=tmp;
    }
    return x;
}
int main()
{
    cin>>n;
    x=0;
    for(i=2;i<n;i++)
    {
        tmpn=n;
        while (tmpn) {x+=tmpn%i;tmpn/=i;}
    }
    y=n-2;
    red=gcd(x,y);
    x/=red;y/=red;
    printf("%i/%i",x,y);
}