#include <bits/stdc++.h>

using namespace std;
#define int long long
const int cnt=5000000;
bool used[cnt];
int mipr[cnt];
int o[cnt];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<cnt;++i)
    {
        used[i]=false;
    }
    used[0]=true;
    used[1]=true;
    for(int i=2;i<cnt;++i)
    {
        if(!used[i])
        {
            for(int j=i;(i*j)<cnt;++j)
            {
                if(!used[i*j])
                {
                used[i*j]=true;
                mipr[i*j]=i;
                }
            }
        }
    }
    int u=0;
    for(int i=2;i<cnt;++i)
    {
        if(!used[i])
        {
            ++u;
            o[i]=u;
        }
    }
    int n;
    cin>>n;
    set <int> a;
    map <int,int> c;
    int k;
    for(int i=0;i<2*n;++i)
    {
        cin>>k;
        a.insert(-k);
        if(c.count(-k)==0)
        {
            c[-k]=1;
        }
        else
        {
            c[-k]++;
        }
    }
    vector <int> b;
    int x;
    int y;
    while(!a.empty())
    {
        x=-(*a.begin());
        if(used[x])
        {
            b.push_back(x);
            y=x/mipr[x];
            c[-x]--;
            c[-y]--;
            if(c[-x]==0)
            {
                a.erase(-x);
            }
            if(c[-y]==0)
            {
                a.erase(-y);
            }
        }
        else
        {
            y=o[x];
            b.push_back(y);
            c[-x]--;
            c[-y]--;
            if(c[-x]==0)
            {
                a.erase(-x);
            }
            if(c[-y]==0)
            {
                a.erase(-y);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}