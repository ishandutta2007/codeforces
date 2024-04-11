#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    vector <int> a;
    int n;
    cout<<"?"<<" ";
    for(int i=1;i<=100;++i)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cin>>n;
    for(int i=1;i<=100;++i)
    {
        a.push_back(i^n);
    }
    vector <int> b;
    int x;
    x=(1<<14);
    bool used[x];
    int h[x];
    for(int i=0;i<x;++i)
    {
        used[i]=false;
        h[i]=(-1);
    }
    int y=0;
    while(b.size()<100)
    {
        if(!used[y])
        {
            b.push_back(y);
            for(int i=0;i<100;++i)
            {
                for(int j=0;j<100;++j)
                {
                    used[(y^(a[i])^(a[j]))]=true;
                }
                h[(y^(a[i]))]=a[i];
            }
        }
        else
        {
            ++y;
        }
    }
    cout<<"?"<<" ";
    for(int i=0;i<100;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int u;
    cin>>u;
    cout<<"!"<<" "<<h[u]<<endl;
    cout.flush();
    return 0;
}