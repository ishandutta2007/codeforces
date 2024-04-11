#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    if(n%4==3 || n%4==0)
    {
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}