#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    if(n==1)
        return cout<<1,0;
    long long l=1,r=n;
    while(r-l>1)
    {
        long long m=(l+r)/2;
        if((1.0*m*(m+1)/2)<n)
            l=m;
        else
            r=m;
    }
    cout<<n-l*(l+1)/2;
    /*cout<< l*(l+1)/2  <<" : "<< l <<'\n' <<
           l*(l+1)/2+1<<" : "<< 1 <<'\n' <<
           n          <<" : "<< n-l*(l+1)/2 <<'\n' <<
           r*(r+1)/2  <<" : "<< r <<'\n' <<
           r*(r+1)/2+1<<" : "<< 1 <<'\n';*/
}