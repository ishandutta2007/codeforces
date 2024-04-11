#include <iostream>
using namespace std;
long long n,x;
main()
{
    cin>>n;
    if (n==1){cout<<"0 1"<<endl;return 0;}
    x=n/7*2;
    if (n%7==6)
        x++;
    cout<<x<<" "<<max((n-1)/7*2+1,(n-2)/7*2+2)<<endl;
}