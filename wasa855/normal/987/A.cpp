#include<bits/stdc++.h>
using namespace std;
bool a[10];
//purple, green, blue, orange, red, yellow
int main()
{
    string t;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        if(t=="purple")
        {
            a[1]=true;
        }
        if(t=="green")
        {
            a[2]=true;
        }
        if(t=="blue")
        {
            a[3]=true;
        }
        if(t=="orange")
        {
            a[4]=true;
        }
        if(t=="red")
        {
            a[5]=true;
        }
        if(t=="yellow")
        {
            a[6]=true;
        }
    }
    //Power, Time, Space, Soul, Reality, Mind
    int ans=0;
    for(int i=1;i<=6;i++)
    {
        if(a[i]==false)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    if(a[1]==false)
    {
        printf("Power\n");
    }
    if(a[2]==false)
    {
        printf("Time\n");
    }
    if(a[3]==false)
    {
        printf("Space\n");
    }
    if(a[4]==false)
    {
        printf("Soul\n");
    }
    if(a[5]==false)
    {
        printf("Reality\n");
    }
    if(a[6]==false)
    {
        printf("Mind\n");
    }
    return 0;
}