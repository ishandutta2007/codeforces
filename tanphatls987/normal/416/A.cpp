#include <iostream>

using namespace std;

const long int maxi=1000000000;
int main()
{
    long int n,l,i,r,x;
    string s,ans;
    cin>>n;
    l=-maxi-1;r=maxi+1;
    for(i=0;i<n;i++)
    {
        cin>>s>>x>>ans;
        if (s==">=")
        {
            if (ans=="Y") {if (x>=l) l=x;}else if (x<=r) r=x-1;
        }
        if (s==">")
        {
            if (ans=="Y") {if (x>=l) l=x+1;}else if (x<=r) r=x;
        }
        if (s=="<=")
        {
            if (ans=="Y") {if (x<=r) r=x;}else if (x>=l) l=x+1;
        }
        if (s=="<")
        {
            if (ans=="Y") {if (x<=r) r=x-1;}else if (x>=l) l=x;
        }
    }
    if (l<=r) cout<<l;else cout<<"Impossible";
}