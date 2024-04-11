#include <bits/stdc++.h>

using namespace std;
#define int long long
bool checkarifm(vector <int> a)
{
    if(a.size()==1)
    {
        return true;
    }
    else
    {
        int d=a[1]-a[0];
        for(int i=0;i<a.size();++i)
        {
            if(a[i]!=(a[0]+d*i))
            {
                return false;
            }
        }
        return true;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <int> a;
    int k;
    int v;
    map <int,int> t;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        t[k]=i;
        a.push_back(k);
    }
    int d;
    sort(a.begin(),a.end());
    d=a[1]-a[0];
    for(int i=2;i<n;++i)
    {
        if(a[i]!=(a[0]+d*i))
        {
            v=a[i];
            a.erase(a.begin()+i);
            if(checkarifm(a))
            {
                cout<<t[v]+1;
                return 0;
            }
            else
            {
                a.insert(a.begin()+i,v);
                v=a[0];
                a.erase(a.begin());
                if(checkarifm(a))
                {
                cout<<t[v]+1;
                return 0;
                }
                a.insert(a.begin(),v);
                v=a[1];
                a.erase(a.begin()+1);
                if(checkarifm(a))
                {
                cout<<t[v]+1;
                return 0;
                }
                a.insert(a.begin()+1,v);
                cout<<(-1);
                return 0;
            }
        }
    }
    cout<<t[a[0]]+1;
    return 0;
}