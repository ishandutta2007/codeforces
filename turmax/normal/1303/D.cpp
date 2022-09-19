#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> a,int x) {
    //cout<<x<<" x "<<endl;
    if (x == 0) {
        return 0;
    }
    int n = a.size();
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ++s;
        } else {
            break;
        }
    }
    vector <int> b;
    for(int i=0;i<(s/2);++i)
    {
        b.push_back(1);
    }
    for(int i=s;i<n;++i)
    {
        b.push_back(a[i]/2);
    }
    if ((x%2)==(s%2))
    {
        //cout<<" rfdsa "<<endl;
        return go(b,x/2);
    }
    if(s>=x)
    {
        return 0;
    }
    if(s!=0)
    {
        if(s%2==0)
        {
            b.erase(b.begin());
        }
        return go(b,x/2);
    }
    if(s==0)
    {
        int u=a[0];
        //cout<<u<<" u "<<endl;
        vector <int> c;
        int s=0;
        while(u>=1)
        {
            u/=2;
            if(u)
                c.push_back(u);
            ++s;
        }
        reverse(c.begin(),c.end());
        for(int i=1;i<n;++i)
        {
            c.push_back(a[i]);
        }
        //cout<<s<<" s "<<endl;
        return go(c,x)+s-1;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n,m;
        cin>>n>>m;
        vector <int> a(m);
        for(int i=0;i<m;++i)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int sum=0;
        for(int i=0;i<m;++i)
        {
            sum+=a[i];
        }
        if(sum<n)
        {
            cout<<(-1)<<endl;
            continue;
        }
        cout<<go(a,n)<<endl;
    }
    return 0;
}