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
    int n;
    cin>>n;
    vector <pair <int,int> > a(2*n);
    int s1=0,s2=0;
    for(int i=0;i<(2*n);++i)
    {
        cin>>a[i].first;a[i].second=(i+1);
        if(a[i].first%2==0) s2++;
        else s1++;
    }
    if(s1%2==0)
    {
        bool h=true;
        for(int i=0;i<2*n;++i)
        {
            if(!h)
            {
                break;
            }
            for(int j=(i+1);j<2*n;++j)
            {
                if(a[i].first%2==a[j].first%2)
                {
                    a.erase(a.begin()+j);a.erase(a.begin()+i);
                    h=false;
                    break;
                }
            }
        }
    }
    else
    {
        bool h=true;
        for(int i=0;i<2*n;++i)
        {
            if(!h)
            {
                break;
            }
            for(int j=(i+1);j<2*n;++j)
            {
                if(a[i].first%2!=a[j].first%2)
                {
                    a.erase(a.begin()+j);a.erase(a.begin()+i);
                    h=false;
                    break;
                }
            }
        }
    }
    bool used[a.size()];
    for(int i=0;i<a.size();++i) used[i]=false;
    for(int i=0;i<a.size();++i)
    {
        for(int j=(i+1);j<a.size();++j)
        {
            if((a[i].first+a[j].first)%2==0)
            {
                if(!used[i] && !used[j])
                {
                    used[i]=true;used[j]=true;
                cout<<a[i].second<<" "<<a[j].second<<endl;
                break;
                }
            }
        }
    }
    }
    return 0;
}