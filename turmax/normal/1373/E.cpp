#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[19];
int f(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<19;++i)
    {
        po[i]=u;
        u*=10;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector <int> v;
        for(int i=1;i<18;++i)
        {
            for(int j=1;j<=10;++j)
            {
                for(int h=0;h<9;++h)
                {
                int sum=0;
                int x=po[i]-j+po[i]*h;
                for(int z=0;z<=k;++z)
                {
                    sum+=f(x+z);
                }
                if(sum>n || ((n-sum)%(k+1))!=0)
                {
                    continue;
                }
                else
                {
                    int u=(i+1);
                    int o=(n-sum)/(k+1);
                    while(o>=9)
                    {
                        //cout<<o<<" o "<<endl;
                        x+=po[u]*9;
                        ++u;
                        o-=9;
                    }
                    x+=po[u]*o;
                    v.push_back(x);
                }
                }
            }
        }
        sort(v.begin(),v.end());
        if(!v.empty())
        {
            cout<<v[0]<<endl;
        }
        else
        {
            cout<<(-1)<<endl;
        }
    }
    return 0;
}