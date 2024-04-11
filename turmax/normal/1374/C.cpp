#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i<=3 && (i*i)<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sh=0;
    int mi=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='(') ++sh;
        else --sh;
        mi=min(mi,sh);
    }
    cout<<(-mi)<<endl;
    }
    return 0;
}