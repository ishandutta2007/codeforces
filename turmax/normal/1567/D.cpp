#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[10];
vector <int> go(vector <int> cnt,int n)
{
    int ma=*max_element(cnt.begin(),cnt.end());
    if(ma<=(9*n-9))
    {
        for(int i=0;i<10;++i)
        {
            if(cnt[i]>0)
            {
                cnt[i]--;
                vector <int> z=go(cnt,n-1);
                z.push_back(po[i]);
                return z;
            }
        }
    }
    vector <int> z(n);
    for(int i=0;i<10;++i)
    {
        int o=cnt[i];
        for(int j=0;j<(o/9);++j)
        {
            z[j]+=po[i]*9;
        }
        z[o/9]+=po[i]*(o%9);
    }
    return z;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int s,n;
        cin>>s>>n;
        vector <int> v;
        for(int i=0;i<10;++i)
        {
            int o=1;
            for(int j=0;j<i;++j) o*=10;
            int z=(s/o)%10;
            for(int i=0;i<z;++i) v.push_back(o);
        }
        while(v.size()<n)
        {
            for(int j=0;j<v.size();++j)
            {
                if(v[j]>=10)
                {
                    int o=v[j];
                    v.erase(v.begin()+j);
                    for(int k=0;k<10;++k)
                    {
                        v.insert(v.begin()+j,o/10);
                    }
                    break;
                }
            }
        }
        int sum=0;
        vector <int> cnt(10);
        for(int i=0;i<10;++i) cnt[i]=0;
        po[0]=1;for(int i=1;i<10;++i) po[i]=po[i-1]*10;
        for(auto h:v)
        {
            for(int i=0;i<10;++i) if(po[i]==h) cnt[i]++;
        }
        vector <int> h=go(cnt,n);
        for(auto z:h) cout<<z<<' ';
        cout<<endl;
    }
    return 0;
}