#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    vector <pair<int,int> > c(n);
    int k;
    vector <int> b(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
        c[i]={k,i};
        b[k]=i;
    }
    b[0]=1e9;
    set <pair<int,int> > d;
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    d.insert({-1,0});
    d.insert({n,0});
    int x,y;
    pair <int,int> v;
    set <pair<int,int> >::iterator iter;
    int sum;
    sum=0;
    for(int i=0;i<n;++i)
    {
        v={c[i].second,c[i].first};
        iter=d.lower_bound(v);
        x=(*iter).first;
        x--;
        iter--;
        y=(*iter).first;
        y++;
        d.insert(v);
        if((x-v.first)>=(v.first-y))
        {
            for(int j=y;j<=v.first;++j)
            {
                if(v.first<=b[v.second-a[j]] && b[v.second-a[j]]<=x)
                {
                    sum++;
                }
            }
        }
        else
        {
            for(int j=v.first;j<=x;++j)
            {
                if(y<=b[v.second-a[j]] && b[v.second-a[j]]<=v.first)
                {
                    sum++;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}