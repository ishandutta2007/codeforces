#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(3);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>c>>a>>b;
        if(a==0&&b==0) continue;
        v[a*b+a].push_back(c);
    }
    for(int i=0;i<3;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    long long ans=1e18;
    for(int i=1;i<v[0].size();i++)
    {
        v[0][i]+=v[0][i-1];
    }
    for(int i=1;i<v[1].size();i++)
    {
        v[1][i]+=v[1][i-1];
    }
    for(int i=1;i<v[2].size();i++)
    {
        v[2][i]+=v[2][i-1];
    }
    for(int i=0;i<=min(k,(int)v[2].size());i++)
    {
        long long t=i?v[2][i-1]:0;
        if(i!=k)
        {
            if(k-i-1<v[0].size()&&k-i-1<v[1].size())
            {
                t+=v[0][k-i-1];
                t+=v[1][k-i-1];
                ans=min(ans,t);
            }
        }
        else
        {
            ans=min(ans,t);
        }
    }

    cout<<(ans==1e18?-1:ans)<<'\n';
}