#include <iostream>

using namespace std;

int main()
{
    int n,i,j,tmp;
    int64_t ans,x;
    cin>>n;
    ans=0; x=0;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if (!tmp) ans+=x;else x++;
    }
    cout<<ans;
}