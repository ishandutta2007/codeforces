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
        int ans=0;
        int a=0;
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            if(c==')') a++;
            else a--;
            ans=max(ans,a);
        }
        cout<<ans<<'\n';
    }
}