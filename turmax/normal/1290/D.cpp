#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> parent;
vector <bool> used;
vector <vector<int> > a;
void go(vector <int> v)
{
    vector <int> u;
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<a[v[i]].size();++j)
        {
            if(!used[a[v[i]][j]-1])
            u.push_back(a[v[i]][j]);
        }
    }
    char s;
    for(int i=0;i<u.size();++i)
    {
        cout<<"? "<<u[i]<<endl;
        cin>>s;
        if(s=='Y')
        {
            used[u[i]-1]=true;
        }
    }
    cout<<'R'<<endl;
    int x=v[v.size()-1];
    int y=v[0];
    if(x!=y)
    {
        vector <int> z;
        for(int i=0;i<a[x].size();++i)
        {
            if(!used[a[x][i]-1])
            z.push_back(a[x][i]);
        }
        for(int i=0;i<a[y].size();++i)
        {
            if(!used[a[y][i]-1])
            z.push_back(a[y][i]);
        }
        for(int i=0;i<z.size();++i)
        {
        cout<<"? "<<z[i]<<endl;
        cin>>s;
        if(s=='Y')
        {
            used[z[i]-1]=true;
        }
        }
        cout<<'R'<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(n==1)
    {
        cout<<"! "<<1<<endl;
        return 0;
    }
    used.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    a.resize(n/k);
    for(int i=0;i<n;++i)
    {
        a[i/k].push_back(i+1);
    }
    map <int,int> u;
    for(int i=1;i<=(n/k);++i)
    {
        vector <int> v;
        for(int j=0;j<__gcd(n/k,i);++j)
        {
            v.clear();
            int t=j;
            while(true)
            {
                //cout<<t<<endl;
                v.push_back(t);
                t+=i;
                t%=(n/k);
                if(t==j)
                {
                    break;
                }
            }
            go(v);
        }
    }
    int s=0;
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            ++s;
        }
    }
    cout<<"! "<<s<<endl;
    return 0;
}