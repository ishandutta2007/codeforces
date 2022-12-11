#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long int n,t,s,i,j,tmp;
    cin>>n;
    long int ans=0;s=0;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        s+=tmp;
        if (s<0) {ans+=-s;s=0;}
    }
    cout<<ans;
}