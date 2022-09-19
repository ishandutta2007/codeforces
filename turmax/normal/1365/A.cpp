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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    bool is1[n];
    bool is2[m];
    for(int i=0;i<n;++i) is1[i]=true;
    for(int i=0;i<m;++i) is2[i]=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            if(a[i][j])
            {
                is1[i]=false;
                is2[j]=false;
            }
        }
    }
    int s1=0,s2=0;
    for(int i=0;i<n;++i) if(is1[i]) ++s1;
    for(int i=0;i<m;++i) if(is2[i]) ++s2;
    if(min(s1,s2)%2==0)
    {
        cout<<"Vivek"<<endl;
    }
    else
    {
        cout<<"Ashish"<<endl;
    }
    }
    return 0;
}