#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(1)
    {
        if(mp[n]==true) break;
        mp[n]=true;
        ans++;
        n++;
        while(n%10==0)
        {
            n/=10;
        }
    }
    cout<<ans<<endl;
    return 0;
}