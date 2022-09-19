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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <int> a;
    int l=(-1);
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='1')
        {
            a.push_back(i-l-1);
            l=i;
        }
    }
    a.push_back(n-l-1);
    if(a.size()==1)
    {
        int sum=1;
        a[0]--;
        int u1=a[0];
        sum+=(u1/(k+1));
        cout<<sum<<endl;
        continue;
    }
    int sum=0;
    for(int i=1;i<((int) a.size())-1;++i)
    {
        sum+=max(0LL,(a[i]-k)/(k+1));
    }
    int u1=a[0];
    sum+=(u1/(k+1));
    if(a.size()>=2)
    {
        int u2=a[a.size()-1];
        sum+=(u2/(k+1));
    }
    cout<<sum<<endl;
    }
    return 0;
}