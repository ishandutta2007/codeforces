#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1) {cout<<'a'<<endl;continue;}
        if(n%2==0)
        {
            for(int i=0;i<n/2;++i) cout<<'a';
            cout<<'z';
            for(int i=0;i<n/2-1;++i) cout<<'a';
            cout<<endl;
        }
        else
        {
            cout<<'y';
            for(int i=0;i<n/2;++i) cout<<'a';
            cout<<'z';
            for(int i=0;i<n/2-1;++i) cout<<'a';
            cout<<endl;
        }
    }
    return 0;
}