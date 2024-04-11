#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a;
    cin>>a;
    a++;
    if(a==1)
    {
        cout<<"0\n";
    }
    else if(a%2==0)
    {
        cout<<a/2<<endl;
    }
    else
    {
        cout<<a<<endl;
    }
}