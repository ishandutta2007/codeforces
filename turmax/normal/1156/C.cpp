#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n,m;
    cin>>n>>m;
    multiset <int> a;
    vector <int> b;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        a.insert(x);
        b.push_back(x);
    }
    map <int,int> c;
    multiset <int>::iterator iter;
    iter=a.begin();
    for(int i=0;i<a.size();++i)
    {
        if(c.count(*iter)==0)
        {
            c[(*iter)]=i;
        }
        iter++;
    }
    iter=a.begin();
    int sum;
    sum=0;
    a.insert(2*1e9+1);
    c[2*1e9+1]=a.size()-1;
    for(int i=0;i<a.size();++i)
    {
        sum=max(sum,c[(*a.lower_bound((*iter)+m))]-i);
        iter++;
    }
    if(sum<=(n/2))
    {
        cout<<n/2<<endl;
        return 0;
    }
    else
    {
        cout<<(n-sum)<<endl;
    }
    return 0;
}