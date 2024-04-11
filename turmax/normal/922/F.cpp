#include <bits/stdc++.h>

using namespace std;
#define int long long
int curr;
const int maxn=3e5+5;
int d[maxn];
bool used[maxn];
void slv(int n,int k)
{
    if(n<=18)
    {
        for(int mask=0;mask<(1<<n);++mask)
        {
            vector <int> v;
            for(int i=0;i<n;++i)
            {
                if(mask & (1<<i))
                {
                    v.push_back(i+1);
                }
            }
            int sum=0;
            for(int i=0;i<v.size();++i)
            {
                for(int j=0;j<v.size();++j)
                {
                    if(i==j)
                    {
                        continue;
                    }
                    else
                    {
                        if(v[i]%v[j]==0)
                        {
                            ++sum;
                        }
                    }
                }
            }
            if(sum==k)
            {
                cout<<"Yes"<<endl;
                cout<<v.size()<<endl;
                for(auto x:v)
                {
                    cout<<x<<' ';
                }
                exit(0);
            }
        }
        cout<<"No"<<endl;
        exit(0);
    }
    else
    {
        if(curr<k)
        {
            cout<<"No"<<endl;
            exit(0);
        }
        int o=d[n];
        if((curr-o)>=k)
        {
            curr-=o;
            slv(n-1,k);
        }
        else
        {
            for(int i=0;i<=n;++i) used[i]=true;
            int x=(curr-k);
            for(int i=(n/2)+1;i<=n;++i)
            {
                if(d[i]<=x)
                {
                    used[i]=false;
                    x-=d[i];
                }
            }
            vector <int> v;
            for(int i=1;i<=n;++i)
            {
                if(used[i])
                {
                   v.push_back(i);
                }
            }
            cout<<"Yes"<<endl;
            cout<<v.size()<<endl;
            for(auto x:v)
            {
                cout<<x<<' ';
            }
            /*cout<<endl;
            int sum=0;
            for(int i=0;i<v.size();++i)
            {
                for(int j=0;j<v.size();++j)
                {
                    if(i!=j)
                    {
                       if(v[i]%v[j]==0)
                       {
                           sum++;
                       }
                    }
                }
            }
            cout<<sum<<" sum "<<endl;*/
            exit(0);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    curr=0;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j*j<=i;++j)
        {
            if(i%j==0)
            {
                d[i]++;
                if(j*j!=i)
                {
                    d[i]++;
                }
            }
        }
        d[i]--;
        curr+=d[i];
    }
    slv(n,k);
    return 0;
}