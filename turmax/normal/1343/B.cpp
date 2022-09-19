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
    if(n%4==2)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
    vector <int> a;
    vector <int> b;
    int d=0;
    for(int i=1;d<(n/4);i+=2)
    {
        ++d;
        a.push_back(4*i);
        b.push_back(4*i+1);
        b.push_back(4*i+3);
        a.push_back(4*i+4);
    }
    for(int i=0;i<(n/2);++i)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0;i<(n/2);++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}