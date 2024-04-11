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
    vector <int> v;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v.push_back(i);v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(v.back()==1) v.pop_back();
    cout<<n/v.back()<<' '<<(n-n/v.back())<<endl;
    }
    return 0;
}