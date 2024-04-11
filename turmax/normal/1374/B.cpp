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
    vector <int> v=rasl(n);
    if(!v.empty() && *max_element(v.begin(),v.end())>3) {cout<<(-1)<<endl;continue;}
    int c2=0,c3=0;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==2) ++c2;
        else ++c3;
    }
    if(c2>c3) {cout<<(-1)<<endl;continue;}
    cout<<2*c3-c2<<endl;
    }
    return 0;
}