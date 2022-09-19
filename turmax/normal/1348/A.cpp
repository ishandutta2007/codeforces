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
    int s1=(1<<n);
    for(int i=1;i<(n/2);++i)
    {
        s1+=(1<<i);
    }
    int s2=(1<<(n+1))-2-s1;
    cout<<abs(s1-s2)<<endl;
    }
    return 0;
}