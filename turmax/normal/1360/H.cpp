#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <string> a;
vector <int> b;
int n,m;
int po[61];
bool cou(vector <int> v,int x)
{
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==x)
        {
            return true;
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<=60;++i)
    {
        po[i]=u;
        u*=2;
    }
    int t;
    cin>>t;
    while(t--)
    {
    cin>>m>>n;
    a.resize(m);
    b.resize(m);
    for(int i=0;i<m;++i)
    {
        b[i]=0;
        cin>>a[i];
        for(int j=0;j<n;++j)
        {
            b[i]+=po[n-j-1]*(a[i][j]-'0');
        }
        //cout<<b[i]<<" b[i] "<<endl;
    }
    int low=0;
    int up=po[n];
    int sz=po[n]-m;
    for(int i=0;i<n;++i)
    {
        int k=(low+up)/2;
        int l=k;
        for(int j=0;j<m;++j)
        {
            if(k>=b[j])
            {
                l--;
            }
        }
        if((2*l<=(sz-1)))
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    while(cou(b,low))
    {
        low--;
    }
    string ans;
    for(int i=0;i<n;++i)
    {
        if(low & po[i])
        {
            ans+='1';
        }
        else 
        {
            ans+='0';
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    }
    return 0;
}