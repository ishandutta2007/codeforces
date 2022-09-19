#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <bool> used;
bool check(vector <int> z,vector <int> a,int n,int k,int x,int y,int s,int u)
{
    int h=0;
    for(int j=0;j<n;++j)
        {
            if(z[j]==(x+y) && !used[j])
            {
                used[j]=true;
                ++u;
                s+=(x+y)*(a[a.size()-1]);
                a.erase(a.begin()+a.size()-1);
                if(s>=k)
                {
                    return true;
                    h=1;
                    break;
                }
            }
        }
        for(int j=0;j<n;++j)
        {
            if(h==1)
            {
                break;
            }
            if(z[j]==max(x,y) && !used[j])
            {
                used[j]=true;
                ++u;
                s+=max(x,y)*(a[a.size()-1]);
                a.erase(a.begin()+a.size()-1);
                if(s>=k)
                {
                    return true;
                    h=1;
                    break;
                }
            }
        }
        for(int j=0;j<n;++j)
        {
            if(h==1)
            {
                break;
            }
            if(z[j]==min(x,y) && !used[j])
            {
                used[j]=true;
                ++u;
                s+=min(x,y)*(a[a.size()-1]);
                a.erase(a.begin()+a.size()-1);
                if(s>=k)
                {
                    return true;
                    h=1;
                    break;
                }
            }
        }
        if(h==0)
        {
            return false;
        }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n;
    vector <int> a;
    int x,y;
    int v,c,d,k;
    vector <int> z;
    int s;
    int u;
    int h;
    int low,up;
    int o;
    for(int i=0;i<q;++i)
    {
        h=0;
        u=0;
        s=0;
        cin>>n;
        a.clear();
        a.resize(n);
        used.resize(n);
        z.resize(n);
        for(int j=0;j<n;++j)
        {
            cin>>x;
            a[j]=x/100;
            z[j]=0;
            used[j]=false;
        }
        cin>>x>>c>>y>>d>>k;
        sort(a.begin(),a.end());
        for(int j=1;(c*j)<=n;++j)
        {
            z[c*j-1]+=x;
        }
        for(int j=1;(d*j)<=n;++j)
        {
            z[d*j-1]+=y;
        }
        low=0;
        up=n;
        if(!check(z,a,n,k,x,y,s,u))
        {
            cout<<(-1)<<endl;
            continue;
        }
        while(true)
        {
            for(int j=0;j<n;++j)
            {
                used[j]=false;
            }
            if((up-low)==1)
            {
                cout<<up<<endl;
                break;
            }
            o=(up+low)/2;
            if(!check(z,a,o,k,x,y,s,u))
            {
                low=o;
            }
            else
            {
                up=o;
            }
        }
    }
    return 0;
}