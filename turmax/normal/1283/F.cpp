#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> v;
    set <int> o;
    int x;
    int ma=n-1;
    int pr[n];
    for(int i=0;i<n;++i)
    {
        pr[i]=(-1);
    }
    for(int i=0;i<(n-1);++i)
    {
        cin>>x;
        x--;
        if(o.count(x)==0)
        {
            v.push_back(x);
            o.insert(x);
            if(x==ma)
            {
                for(int i=ma;i>=0;i--)
                {
                    if(o.count(i)==0)
                    {
                        ma=i;
                        break;
                    }
                }
            }
            continue;
        }
        else
        {
            v.push_back(ma);
            o.insert(ma);
            for(int i=1;i<v.size();++i)
            {
                pr[v[i]]=v[i-1];
            }
            v.clear();
            for(int i=ma;i>=0;i--)
            {
                if(o.count(i)==0)
                {
                    ma=i;
                    break;
                }
            }
            v.push_back(x);
        }
    }
    v.push_back(ma);
    o.insert(ma);
    for(int i=1;i<v.size();++i)
    {
        pr[v[i]]=v[i-1];
    }
    for(int i=0;i<n;++i)
    {
        if(pr[i]==(-1))
        {
            cout<<(i+1)<<endl;
            break;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(pr[i]!=(-1))
        {
            cout<<(i+1)<<" "<<(pr[i]+1)<<endl;
        }
    }
    return 0;
}