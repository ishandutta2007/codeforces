#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n),last(n);
    int g;
    cin>>g;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        g=__gcd(g,v[i]);
    }
    set<int> ans;
    long long num=0;
    for(int i=0;i<k;i++)
    {
        ans.insert(num%k);
        num+=g;
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans) cout<<x<<' ';

}