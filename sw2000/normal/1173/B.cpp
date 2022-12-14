#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int main()
{
    int n,ans,x=1,y=1;
    cin>>n;
    ans=n/2+1;
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<x<<' '<<y<<endl;
        if(x==y)x++;
        else y++;
    }

    return 0;
}