#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long int x,y,n;
    cin>>x>>y>>n;
    long long int k = pow(10,9) + 7;
    switch(n%6)
    {
        case 0:
        cout<<(2*k+x-y)%k;
        break;
        case 1:
        cout<<(k+x)%k;
        break;
        case 2:
        cout<<(k+y)%k;
        break;
        case 3:
        cout<<(2*k+y-x)%k;
        break;
        case 4:
        cout<<(k-x)%k;
        break;
        case 5:
        cout<<(k-y)%k;
        break;
    }
    return 0;
}