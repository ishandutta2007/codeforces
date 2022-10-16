#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int two=0,three=0;
        while(n%2==0)
        {
            two++;
            n/=2;
        }
        while(n%3==0)
        {
            three++;
            n/=3;
        }
        bool a=true;
        int ans=0;
        if(n!=1) a=0;
        if(two>three) a=0;
        if(a)
        {
            ans+=(three-two)+three;
            cout<<ans<<'\n';
        }
        else cout<<-1<<'\n';
    }
    return 0;
}