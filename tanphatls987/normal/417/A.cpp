#include <iostream>

using namespace std;

int main()
{
    long int num,c,d,n,m,k;
    cin>>c>>d>>n>>m>>k;
    num=n*m-k;
    if ((n*d>c)&&(num>0))
        {if ((num%n)*d+(num/n)*c<((num+n-1)/n)*c) cout<<(num%n)*d+(num/n)*c;else cout<<((num+n-1)/n)*c;}
    else {if (num>0) cout<<num*d;else cout<<0;}
}