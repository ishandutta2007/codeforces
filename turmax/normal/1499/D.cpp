#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e7+5;
int h[maxn];
int mi[maxn];
bool used[maxn];
vector <int> del(int x)
{
    vector <int> v;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v.push_back(i);
            v.push_back(x/i);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    h[1]=1;used[0]=true;used[1]=true;mi[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) continue;
        for(int j=2*i;j<maxn;j+=i)
        {
            if(!used[j])
            {
                used[j]=true;
                mi[j]=i;
            }
        }
    }
    h[2]=2;
    for(int i=3;i<maxn;++i)
    {
        if(!used[i]) {h[i]=2;continue;}
        int x=mi[i];
        if(i%(x*x)==0)
        {
            h[i]=h[i/x];
        }
        else
        {
            h[i]=h[i/x]*2;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int c,d,x;
        cin>>c>>d>>x;
        int ans=0;
        vector <int> v=del(x);
        for(auto h1:v)
        {
            int z=x/h1+d;
            if(z%c==0)
            {
                int z1=z/c;
                //cout<<z1<<" z1 "<<endl;
                ans+=h[z1];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}