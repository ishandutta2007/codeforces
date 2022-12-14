#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;

    if(z==0)
    {
        if(x>y)cout<<"+";
        else if(x==y)cout<<"0";
        else cout<<"-";
        return 0;
    }

    if(abs(x-y)>z)
    {
        if(x>y)cout<<"+";
        else cout<<"-";
    }
    else
    {
        cout<<"?";
    }
    return 0;
}