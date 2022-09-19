#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    cin>>n;
    int x,y,z;
    x=0;
    y=0;
    z=0;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        if(k>0)
        {
            ++x;
        }
        else if(k==0)
        {
            ++y;
        }
        else
        {
            ++z;
        }
    }
    if(z>=(x+y))
    {
        cout<<(-1);
        return 0;
    }
    else if(x>=(z+y))
    {
        cout<<1;
        return 0;
    }
    else
    {
        cout<<0;
        return 0;
    }
    return 0;
}