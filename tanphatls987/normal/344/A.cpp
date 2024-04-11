#include <iostream>

using namespace std;

int main()
{
    long int i,n,next,last;
    cin>>n;
    long int ans=0;
    last=0;
    for(i=0;i<n;i++)
    {
        cin>>next;
        if (next!=last) ans++;
        last=next;
    }
    cout<<ans;
}