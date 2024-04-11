#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    vector <char> v;
    int z=0;
    for(char i='a';z<26;++i)
    {
        ++z;
        v.push_back(i);
    }
    z=0;
    for(char i='A';z<26;++i)
    {
        ++z;
        v.push_back(i);
    }
    z=0;
    for(char i='0';z<10;++i)
    {
        ++z;
        v.push_back(i);
    }
    for(int cyc=0;cyc<t;++cyc)
    {
        int r,c,k;
        cin>>r>>c>>k;
        int sum=0;
        vector <vector <char> > a(r);
        char s;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                cin>>s;
                a[i].push_back(s);
                if(a[i][j]=='R')
                {
                    ++sum;
                }
            }
        }
        int d=(sum+k-1)/k;
        int e=(sum-(d-1)*k);
        int curr=0;
        int u=0;
        //cout<<e<<"   e    "<<endl;
        //cout<<d<<" gtfd "<<endl;
        vector <vector <int> > b(r);
        for(int i=0;i<r;++i)
        {
            b[i].resize(c);
        }
        for(int i=0;i<r;++i)
        {
            if(i%2==0)
            {
            for(int j=0;j<c;++j)
            {
                b[i][j]=curr;
                if(a[i][j]=='R')
                {
                    ++u;
                    if(u>=d || (u>=(d-1) && e<=0))
                    {
                        if(u>=d)
                        {
                            e--;
                        }
                        ++curr;
                        u=0;
                    }
                }
            }
            }
            else
            {
            for(int j=(c-1);j>=0;--j)
            {
                b[i][j]=curr;
                if(a[i][j]=='R')
                {
                    ++u;
                    if(u>=d || (u>=(d-1) && e<=0))
                    {
                        if(u>=d)
                        {
                            e--;
                        }
                        ++curr;
                        u=0;
                    }
                }
            }
            }
        }
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                if(b[i][j]<k)
                cout<<v[b[i][j]];
                else
                cout<<v[k-1];
            }
            cout<<endl;
        }
    }
    return 0;
}