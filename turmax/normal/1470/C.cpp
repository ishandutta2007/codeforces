#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int query(int x)
{
    x%=n;x+=n;x%=n;
    if(x==0) x=n;
    cout<<"? "<<x<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>n>>k;
    int curr=0;
    bool h=false;
    int l=1,r=1e18;
    if(n<=12)
    {
        int cyc=1;query(1);
        for(int i=0;i<n;++i)
        {
            //cout<<i<<" i1 "<<endl;
            int i1=i;
            vector <int> v;
            for(int j=0;j<n;++j) v.push_back(k);
            for(int oper=0;oper<cyc;++oper)
            {
                vector <int> v1;
                v1.resize(n);for(int j=0;j<n;++j) v1[j]=0;
                for(int j=0;j<n;++j)
                {
                    if(j==i)
                    {
                        v1[(j+1)%n]+=v[j];
                    }
                    else
                    {
                        v1[(j+1)%n]+=((v[j]+1)/2);
                        v1[(j-1+n)%n]+=v[j]/2;
                    }
                }
                //for(auto h:v) cout<<h<<' ';
                //cout<<endl;
                v=v1;
            }
            bool u=true;
            for(int oper=0;oper<50;++oper)
            {
                ++cyc;
                int i=rand()%n;
                if(query(i+1)!=v[i])
                {
                    u=false;
                    break;
                }
                vector <int> v1;
                v1.resize(n);for(int j=0;j<n;++j) v1[j]=0;
                for(int j=0;j<n;++j)
                {
                    if(j==i1)
                    {
                        v1[(j+1)%n]+=v[j];
                    }
                    else
                    {
                        v1[(j+1)%n]+=((v[j]+1)/2);
                        v1[(j-1+n)%n]+=v[j]/2;
                    }
                }
                v=v1;
            }
            if(u) {cout<<"! "<<(i+1)<<endl;return 0;}
        }
    }
    for(int i=0;i<1000;++i)
    {
        if((r-l)==1)
        {
            r%=n;r+=n;r%=n;
            if(r==0) r=n;
            cout<<"! "<<r<<endl;
            exit(0);
        }
        if(h)
        {
            int z=(l+r)/2;
            curr=(z-i);
            int o=query(curr);
            if(o<k)
            {
                r=z;
            }
            else
            {
                l=z;
            }
        }
        curr+=i;
        int o=query(curr);
        if(o<k)
        {
            h=true;
            l=curr;r=(curr+i);//[l;r)
        }
    }
    return 0;
}